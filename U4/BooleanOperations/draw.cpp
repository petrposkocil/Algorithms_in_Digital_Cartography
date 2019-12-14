#include "draw.h"
#include "qpointfb.h"
#include <QtGui>
#include <fstream>
#include <QDebug>
#include <algorithms.h>

Draw::Draw(QWidget *parent) : QWidget(parent)
{
    ab = true;
    ab_select = true;
    paint_active = false;
}

void Draw::mousePressEvent(QMouseEvent *event)
{

    if (paint_active == true)
    {
        QPointFB q(event->x(), event->y());

         //Add to A
         if(ab)
             a.push_back(q);

         //Add to B
         else
             b.push_back(q);

         repaint();
    }

    else
    {
        if (ab_select == true)
            a.clear();
        else
            b.clear();

        QPointF q(event->x(), event->y());
        setQ(q);
        std::vector<QPolygonF> pols = getPolygons();

        // Get polygons one by one
        int index;

        // Compute result - position of point and polygon
        for(unsigned int i = 0; i < pols.size(); i++)
        {
            QPolygonF pol = pols[i];
            int result = Algorithms::getPositionWindingSelect(q, pol);
            index = result;
            if (index == 1)
            {
                if(ab_select == true)
                {
                    for (int i = 0; i < pol.size(); i++)
                    {
                        double x = pol[i].x();
                        double y = pol[i].y();
                        QPointFB pa(x, y);
                        a.push_back(pa);
                    }
                }
                else
                {
                    for (int i = 0; i < pol.size(); i++)
                    {
                        double x = pol[i].x();
                        double y = pol[i].y();
                        QPointFB pb(x, y);
                        b.push_back(pb);
                    }
                }
            }

        }
         repaint();
    }

}

void Draw::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.begin(this);

    // Draw imported polygons
    for(unsigned int i = 0; i < polygons.size(); i++)
    {
        // Polygon of i index value from file
        QPolygonF this_polygon = polygons[i];

        QPen pols;
        pols.setWidth(2);
        QColor color(255,0,0);
        switch (i)
        {
        case 0: color = (Qt::cyan); break;
        case 1: color = (Qt::magenta); break;
        case 2: color = (Qt::black); break;
        case 3: color = (Qt::yellow);
        }
        pols.setColor(color);
        painter.setPen(pols);

        // Draw polygon of i index
        painter.drawPolygon(this_polygon);
    }

    //Draw A
    QPen pA(Qt::green);
    pA.setWidth(4);
    painter.setPen(pA);
    drawPolygon(painter, a);

    //Draw B
    QPen pB(Qt::blue);
    pB.setWidth(4);
    painter.setPen(pB);
    drawPolygon(painter, b);

    //Draw edges
    QPen pE(Qt::red);
    pE.setWidth(5);
    painter.setPen(pE);

    for(int i = 0; i < res.size(); i++)
    {
        painter.drawLine(res[i].getStart(), res[i].getEnd());
    }

    painter.end();
}

void Draw::drawPolygon(QPainter &painter, std::vector<QPointFB> &polygon)
{
    //Draw polygon
    QPolygon polyg;
    for(int i = 0; i < polygon.size(); i++)
    {
        polyg.append(QPoint (polygon[i].x(), polygon[i].y()));
    }

    painter.drawPolygon(polyg);
}

void Draw::importPolygons(std::string &path, std::vector<QPolygonF> &polygons,  QSizeF &canvas_size)
{
    // Inner variables of import - file structure
    int n;
    double x;
    double y;
    QPolygonF polygon;
    double h = canvas_size.height() - 20.0;
    double w = canvas_size.width() - 20.0;
    double min_x = 10e10;    double min_y = 10e10;
    double max_x = -10e10;    double max_y = -10e10;


    std::ifstream myfile(path);

    if(myfile.is_open())
    {
        qDebug() << "File is open...";

        while(myfile >> n >> x >> y)        // Line by line
        {
            // Search min and max coodrinate
            if(x < min_x) min_x = x;
            if(x > max_x) max_x = x;
            if(y < min_y) min_y = y;
            if(y > max_y) max_y = y;

        }

        qDebug() << "local values: " << min_x << max_x << min_y << max_y;

        myfile.clear();
        myfile.seekg(0);

        double x_coef = w/(max_x-min_x);
        double y_coef = h/(max_y-min_y);

        while(myfile >> n >> x >> y)        // Line by line
        {

            if(n == 1)                      // If (n == 1) creates a new polygon every time the n = 1
            {
               if(polygon.empty() == FALSE)
               {
                   polygons.push_back(polygon);
               }
               polygon.clear();

               //Reduce coordinates
               x = (x - min_x) * x_coef;
               y = (y - min_y) * y_coef;
               polygon << QPointF(x, y);
            }

            else
            {
                //Reduce coordinates
                x = (x - min_x) * x_coef;
                y = (y - min_y) * y_coef;
                polygon << QPointF(x, y);
            }
        }

        // Save the last polygon
        polygons.push_back(polygon);
        polygon.clear();

        // Print out the variable polygons
        for(unsigned int i = 0; i<polygons.size(); i++)
        {
            qDebug() << polygons[i];
        }
        myfile.close();
    }
}
