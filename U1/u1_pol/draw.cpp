#include <cmath>
#include <QtGui>
#include <QMessageBox>
#include "draw.h"
#include "algorithms.h"
#include "qdebug.h"


Draw::Draw(QWidget *parent) : QWidget(parent)
{
    // Initial value for cursor input of point Q - Graphical input from Qwidget - Draw button on/off
    draw_point = false;

    // Set initial offset for cursor to make it disapear from Qwidget after launch
    q.setX(-50);
    q.setY(-50);
}

void Draw::paintEvent(QPaintEvent *e)
{
    // Draw point Q and polygons
    QPainter painter(this);

    // Start drawing
    painter.begin(this);

    // Draw imported polygons
    for(unsigned int i = 0; i < polygons.size(); i++)
    {
        // Polygon of i index value from file
        QPolygonF this_polygon = polygons[i];

        // Draw polygon of i index
        painter.drawPolygon(this_polygon);
    }

    QPolygonF polygon_result;

    // Set brush - fillup the polygon which contains point Q
    QBrush brush;
    brush.setColor(Qt::magenta);
    brush.setStyle(Qt::Dense2Pattern);
    QPainterPath path;

    // Draw polygon with point inside
    for(unsigned int i = 0; i < result.size(); i++)
    {
        if(result[i] == 1)
        {
            polygon_result << polygons[i];
            qDebug() << polygon_result;
            path.addPolygon(polygon_result);
            painter.fillPath(path, brush);
            painter.drawPolygon(polygon_result);
            polygon_result.clear();
        }
    }

    // Draw point Q at the end - will not be overdrawn by brush
    painter.setPen(QPen(Qt::black, 2));
    painter.drawEllipse(static_cast<int>(q.x()) -10, static_cast<int>(q.y()) -10, 20, 20);

    // Stop drawing
    painter.end();
}

void Draw::mousePressEvent(QMouseEvent *e)
{
    // Saving coordinates of point Q from cursor input
    if(!draw_point)
    {
        return;
    }
    q.setX(e->x());
    q.setY(e->y());
    repaint();
}

void Draw::setDrawPoint()
{
    // Turn on/off the cursor input of point Q
    draw_point = !draw_point;
}

void Draw::clearCanvas()
{
    // Clear the Qwidget - Canvas
    pol.clear();
    polygons.clear();
    result.clear();

    // Reset initial coordinates of point Q
    q.setX(-50);
    q.setY(-50);
    repaint();
}

bool Draw::importPolygons(std::string &path)
{
    // Inner variables of import - file structure
    int n;                                  // Vertex index in each polygon
    double x;
    double y;
    QPolygonF polygon;

    std::ifstream myfile(path);
    if(myfile.is_open())
    {
        qDebug() << "File is open...";

        while(myfile >> n >> x >> y)        // Line by line
        {
            if(n == 1)                      // If (n == 1) creates a new polygon every time the n = 1
            {
               if(polygon.empty() == FALSE)
               {
                   polygons.push_back(polygon);
               }
               polygon.clear();
               polygon << QPointF(x, y);
            }

            else
            {
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

        QMessageBox msgBox;
        msgBox.setText("Import succesfull");
        msgBox.exec();
        return true;
    }

    QMessageBox msgBox;
    msgBox.setText("Something went wrong! Check the file again");
    msgBox.exec();
    return false;
}
