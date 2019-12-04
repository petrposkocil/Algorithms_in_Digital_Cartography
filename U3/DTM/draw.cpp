#include "draw.h"
#include "widget.h"
#include "algorithms.h"
#include <QColor>
#include <QtMath>
#include <QPainter>
#include <QDebug>
#include <fstream>
#include <QMessageBox>
#include <vector>
#include <QRandomGenerator>
#include <QColorDialog>


Draw::Draw(QWidget *parent) : QWidget(parent)
{

}

void Draw::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.begin(this);

    //Draw points
    for (int i = 0; i < points.size(); i++)
    {
        painter.drawEllipse(points[i].x() - 5, points[i].y() - 5, 10, 10);
    }

    //Draw edges
    QPen p(Qt::lightGray, 0.5);
    painter.setPen(p);

    for (int i = 0; i < dt.size(); i++)
    {
        painter.drawLine(dt[i].getStart(), dt[i].getEnd());
    }

    if (method == 0)
    {
        //Draw slope
        double k = 255.0 / 180;
        for (Triangle t : dtm)
        {
            //Get triangle vertices
            QPoint3D p1 = t.getP1();
            QPoint3D p2 = t.getP2();
            QPoint3D p3 = t.getP3();
            int slope = 255 - t.getSlope() * k;

            //Set color brush
            QColor c(slope, slope, slope);
            painter.setBrush(c);

            //Create polygon
            QPolygonF triangle;
            triangle.append(QPointF(p1.x(), p1.y()));
            triangle.append(QPointF(p2.x(), p2.y()));
            triangle.append(QPointF(p3.x(), p3.y()));

            painter.drawPolygon(triangle);
        }
    }

    else if (method == 1)
    {
        //Draw aspect
        for (Triangle t : dtm)
        {
            //Get triangle vertices
            QPoint3D p1 = t.getP1();
            QPoint3D p2 = t.getP2();
            QPoint3D p3 = t.getP3();
            int aspect = t.getAspect();

            //Set color brush
            QColor c;
            c.setHsv(aspect, 255, 255);
            painter.setBrush(c);

            //Create polygon
            QPolygonF triangle;
            triangle.append(QPointF(p1.x(), p1.y()));
            triangle.append(QPointF(p2.x(), p2.y()));
            triangle.append(QPointF(p3.x(), p3.y()));

            painter.drawPolygon(triangle);
        }
    }


    else
    {
        int h_min = 10e7;
        int h_max = -999;

        for (Triangle t : dtm)
        {

            QPoint3D p1 = t.getP1();
            QPoint3D p2 = t.getP2();
            QPoint3D p3 = t.getP3();
            double h = (p1.getZ() + p2.getZ() + p3.getZ())/3;
            if (h < h_min)
            {
                h_min = h;
            }
            if (h > h_max)
            {
                h_max = h;
            }
        }
        qDebug() << "Hmin: "<< h_min << "Hmax: " << h_max;
        //Draw hypsometry
        for (Triangle t : dtm)
        {
            //Get triangle vertices
            QPoint3D p1 = t.getP1();
            QPoint3D p2 = t.getP2();
            QPoint3D p3 = t.getP3();

            // Hierarchy in hypsomerty
            double k = 255.0 / (h_max - h_min);

            // Height of a polygon centroid            
            double h = ((p1.getZ() + p2.getZ() + p3.getZ())/3)*k;
            double h_min = h;
            int h_ = h;

            QColor gradient1(getColor1());
            QColor gradient2(getColor2());

            // Colors for the gradient
            double start_R = gradient1.red();//128;
            double start_G = gradient1.green();//1;
            double start_B = gradient1.blue();//1;
            qDebug()<< "start" << start_R << start_G << start_B;
            double end_R = gradient2.red();//255;
            double end_G = gradient2.green();//248;
            double end_B = gradient2.blue();//220;
            qDebug()<< "end" << end_R << end_G << end_B;
            double new_r, new_g, new_b;
            int new_rr, new_gg, new_bb;

            // Gradient interval division
            double diff_r = fabs(start_R-end_R)/((h_max - h_min)/2.0);//dtm.size();
            double diff_g = fabs(start_G-end_G)/((h_max - h_min)/2.0);//dtm.size();
            double diff_b = fabs(start_B-end_B)/((h_max - h_min)/2.0);//dtm.size();
            qDebug()<< "diff" << diff_r << diff_g << diff_b;

            if (start_R < end_R)
            {
                new_r = start_R + (h_*diff_r);
            }
            else
            {
                new_r = start_R - (h_*diff_r);
            }

            if (start_G < end_G)
            {
                new_g = start_G + (h_*diff_g);
            }
            else
            {
                new_g = start_G - (h_*diff_g);
            }

            if (start_B < end_B)
            {
                new_b = start_B + (h_*diff_b);
            }
            else
            {
                new_b = start_B - (h_*diff_b);
            }

            qDebug()<< "new" << new_r << new_g << new_b;
            new_rr = new_r;
            new_gg = new_g;
            new_bb = new_b;
            qDebug()<< "new_int:" << new_rr << new_gg << new_bb;
            QColor c(new_rr, new_gg, new_bb);
            painter.setBrush(c);

            //Create polygon
            QPolygonF triangle;
            triangle.append(QPointF(p1.x(), p1.y()));
            triangle.append(QPointF(p2.x(), p2.y()));
            triangle.append(QPointF(p3.x(), p3.y()));

            painter.drawPolygon(triangle);
        }

   }


    //Draw countour lines
    QColor cont1(210,180,140);
    QPen q(cont1, 1);

    for (int i = 0; i < contours.size(); i++)
    {
        painter.setPen(q);
        painter.drawLine(contours[i].getStart(), contours[i].getEnd());
    }

    //Draw main countour lines
    QColor cont2(190,180,140);
    QColor text(165,42,42);
    QPen r(cont2, 1.5);
    QPen r2(text, 1);

    for (int i = 0; i < mainContours.size(); i++)
    {
        // Main contour lines
        painter.setPen(r);
        painter.drawLine(mainContours[i].getStart(), mainContours[i].getEnd());

        if (cont_heights_vsible == TRUE)
        {
            // Main contour height text
            QPoint3D sPoint = mainContours[i].getStart();
            double center_x = (mainContours[i].getStart().x() + mainContours[i].getEnd().x())/2;
            double center_y = (mainContours[i].getStart().y() + mainContours[i].getEnd().y())/2;
            QString contourValue = QString::number(sPoint.getZ());

            double omega_r = qAtan2((mainContours[i].getEnd().y() - mainContours[i].getStart().y()),(mainContours[i].getEnd().x() - mainContours[i].getStart().x()));
            double omega_d = omega_r * (180/M_PI) + 180;
            qDebug() << "omega: " <<omega_d;

            QFont f("Arial", 8);
            f.setBold(TRUE);
            painter.setFont(f);
            painter.setPen(r2);
            painter.save();
            painter.translate(center_x,center_y);
            painter.rotate(omega_d);
            if (i%10 == 0)
            {
                painter.drawText(-3, 3 ,contourValue);
            }
            painter.restore();

      }
    }
    painter.end();
}

void Draw::mousePressEvent(QMouseEvent *event)
{
    //Get coordinates of cursor
    QPoint3D p;
    p.setX(event ->x());
    p.setY(event ->y());
    double random = std::rand() * 200.0 / RAND_MAX;
    p.setZ(random);

    //Add point to the list
    points.push_back(p);

    repaint();
};

void Draw::importPoints(std::string &path, std::vector<QPoint3D> &points,  QSizeF &canvas_size, double &z_min, double &z_max)
{
    double x, y, z;
        QPoint3D p;


        //go through file and load points into poly_pol (storing all polygons)
        double min_x = std::numeric_limits<double>::max();
        double min_y = std::numeric_limits<double>::max();
        double max_x = std::numeric_limits<double>::min();
        double max_y = std::numeric_limits<double>::min();
        double min_z = std::numeric_limits<double>::max();
        double max_z = std::numeric_limits<double>::min();


        std::ifstream myfile(path);
        if(myfile.is_open())
        {
            qDebug() << "File is open";
            while(myfile >> x >> y >> z)        //read file line by line
            {
                p.setX(x);
                p.setY(y);
                p.setZ(z);

                points.push_back(p);

                if(x < min_x) min_x = x;
                if(x > max_x) max_x = x;
                if(y < min_y) min_y = y;
                if(y > max_y) max_y = y;
                if(z < min_z) min_z = z;
                if(z > max_z) max_z = z;
            }

            myfile.close();
        }

        //scale points to canvas size
            double h = canvas_size.height() - 40;
            double w = canvas_size.width() - 40;

            double x_coef = w/(max_x-min_x);
            double y_coef = h/(max_y-min_y);
            double scale_z = z_max / (max_z - min_z);

            for(unsigned int i = 0; i < points.size(); i++)
            {
                points[i].setX((points[i].x()-min_x)*x_coef);
                points[i].setY((points[i].y()-min_y)*y_coef);
                points[i].setZ((points[i].getZ() - min_z)*scale_z);
            }
}

std::vector<QPoint3D> Draw::generateTerrainHill(QSizeF &canvas_size, double &z_min, double &z_max)
  {
      std::vector<QPoint3D> points;
      QPoint3D point;
      int n_points = 1000;

      // Set the widget size
      double height = canvas_size.height();
      double width = canvas_size.width();

      QPoint center(width/2,height/2);
      double a = height/3;
      double b = width/3;
      double x ,y;
      double z = 0;
      int iteration = 10;

      for (int i = 1; i < iteration; i++)
      {
          z += (z_max - z_min) / iteration;
          for (double angle=0; angle<2*M_PI; angle+=(2*M_PI/n_points*iteration))
          {

            double random = rand() %15+10;
            x = (center.x() + random) + a*cos( angle );
            y = (center.y() + random) + b*sin( angle );
            y += 5;

            point.setX(x);
            point.setY(y);
            point.setZ(z);
            points.push_back(point);

            qDebug() << point.getZ();

          }
          a-= ((height/2)/iteration);
          b-= ((width/2)/iteration);

      }

      return points;
  }

std::vector<QPoint3D> Draw::generateValley(QSizeF &canvas_size, double &z_min, double &z_max)
  {
    std::vector<QPoint3D> points;
    QPoint3D point;
    double x, y, z;
    int n_points = 1000;
    int min_z = z_min;
    int max_z = z_max - min_z;

    // Set the widget size
    double height = canvas_size.height();
    double width = canvas_size.width();

    const int maximum_number = 1000;//max_z;
    const int minimum_number = 800;//4*max_z/5;

    for (int i = 1; i < n_points/5; i++)
    {
        x = 15 + rand() %20+1;
        y = i * (height/(n_points/5)) + rand() %20+1;
        const int z = (rand() % (maximum_number + 1 - minimum_number)) + minimum_number;
        point.setX(x);
        point.setY(y);
        if (z <= max_z && z >= 4*max_z/5)
        {
            point.setZ(z);
        }
        else
        {
            const int z = (rand() % (maximum_number + 1 - minimum_number)) + minimum_number;
            point.setZ(z);
        }
        point.setZ(z);
        points.push_back(point);

        qDebug() << x << y << z;
    }

    const int maximum_number2 = 800;//4*max_z/5;
    const int minimum_number2 = 500;//max_z/2;

    for (int i = 1; i < n_points/5; i++)
    {
        x = width/4 + rand() %20+1;
        y = i * (height/(n_points/5)) + rand() %20+1;
        const int z = (rand() % (maximum_number2 + 1 - minimum_number2)) + minimum_number2;
        point.setX(x);
        point.setY(y);
        if (z <= 4*max_z/5 && z >= max_z/2)
        {
            point.setZ(z);
        }
        else
        {
            const int z = (rand() % (maximum_number2 + 1 - minimum_number2)) + minimum_number2;
            point.setZ(z);
        }
        point.setZ(z);
        points.push_back(point);

        qDebug() << x << y << z;
    }

    const int maximum_number3 = 100;//9*max_z/10;
    const int minimum_number3 = 0;

    for (int i = 1; i < n_points/5; i++)
    {
        x = 2*width/4 + rand() %50+1;
        y = i * (height/(n_points/5)) + rand() %20+1;
        const int z = (rand() % (maximum_number3 + 1 - minimum_number3)) + minimum_number3;
        point.setX(x);
        point.setY(y);
        if (z <= 9*max_z/10 && z >= 0)
        {
            point.setZ(z);
        }
        else
        {
            const int z = (rand() % (maximum_number3 + 1 - minimum_number3)) + minimum_number3;
            point.setZ(z);
        }
        point.setZ(z);
        points.push_back(point);

        qDebug() << x << y << z;
    }

    const int maximum_number4 = 800;//4*max_z/5;
    const int minimum_number4 = 500;//max_z/2;

    for (int i = 1; i < n_points/5; i++)
    {
        x = 3*width/4 + rand() %20+1;
        y = i * (height/(n_points/5)) + rand() %20+1;
        const int z = (rand() % (maximum_number4 + 1 - minimum_number4)) + minimum_number4;
        point.setX(x);
        point.setY(y);
        if (z <= 4*max_z/5 && z >= max_z/2)
        {
            point.setZ(z);
        }
        else
        {
            const int z = (rand() % (maximum_number4 + 1 - minimum_number4)) + minimum_number4;
            point.setZ(z);
        }
        points.push_back(point);

        qDebug() << x << y << z;
    }

    const int maximum_number5 = 1000;//max_z;
    const int minimum_number5 = 800;//4*max_z/5;

    for (int i = 1; i < n_points/5; i++)
    {
        x = width - rand() %20+1;
        y = i * (height/(n_points/5)) + rand() %20+1;
        const int z = (rand() % (maximum_number5 + 1 - minimum_number5)) + minimum_number5;
        point.setX(x);
        point.setY(y);
        if (z <= max_z && z >= 4*max_z/5)
        {
            point.setZ(z);
        }
        else
        {
            const int z = (rand() % (maximum_number5 + 1 - minimum_number5)) + minimum_number5;
            point.setZ(z);
        }
        point.setZ(z);
        points.push_back(point);

        qDebug() << x << y << z;
    }

    return points;
}

std::vector<QPoint3D> Draw::generateSaddle(QSizeF &canvas_size, double &z_min, double &z_max)
  {
      std::vector<QPoint3D> points;
      QPoint3D point;
      double x, y, z, cx, cy;

      // Set the widget size
      double height = canvas_size.height();
      double width = canvas_size.width();

      // Widget center
      cx = width/2.0;
      cy = height/2.0;

      // Indexes for the shape
      double a1, b1, a2, b2;
      double m = cx;
      double n = cy;
      double z_increase = 1000/2;
      double z_decrease = 1000/2;

      for (int i = 1; i < 5; i++)
      {
          double a1 = i*(-50);
          double b1 = i*50;
          double a2 = i*(-50);
          double b2 = i*50;
          z_increase += 1000/10;
          z_decrease -= 1000/10;

          m = cx;
          n = cy + 10;
          for (x = 0; x < width; x += 10)
          {
              n = cy + 50;
              x += rand() %10+1;
              y = (sqrt((b1 * b1) * (1 + (((x - m)*(x - m))/(a1 * a1)))) + n) + rand() %10+1;
              if ((y < height-10) && (x < width))
              {
                  point.setX(x);
                  point.setY(y);
                  point.setZ(z_increase);
                  points.push_back(point);
                  qDebug() << "x1: " << x << "y1: " << y << "z1: " << z;
              }
              y = (cy + cy - y);
              if ((y > 10) && (x < width))
              {
                  point.setX(x);
                  point.setY(y);
                  point.setZ(z_increase);
                  points.push_back(point);
                  qDebug() << "x2: " << x << "y2: " << y << "z2: " << z;
              }
          }

          m = cx + 10;
          n = cy;
          for (y = 10; y < height-10; y += 10)
          {
              x += rand() %20+1;
              x = (sqrt((a2 * a2) * (1 + (((y - n) * (y - n))/(b2 * b2)))) + m) + rand() %20+1;
              if ((x < width-10) && (y < height))
              {
                  point.setX(x);
                  point.setY(y);
                  point.setZ(z_decrease);
                  points.push_back(point);
                  qDebug() << "x1: " << x << "y1: " << y << "z1: " << point.getZ();
              }
              x = (cx + cx - x);
              if ((x > 10) && (y < height))
              {
                  point.setX(x);
                  point.setY(y);
                  point.setZ(z_decrease);
                  points.push_back(point);
                  qDebug() << "x2: " << x << "y2: " << y << "z2: " <<  point.getZ();
              }
          }
      }

      return points;
  }
