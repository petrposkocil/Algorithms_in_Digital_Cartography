#include "draw.h"
#include "algorithms.h"
#include <sortbyx.h>
#include <QtGui>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <QtDebug>

Draw::Draw(QWidget *parent) : QWidget(parent)
{

}

 void Draw::mousePressEvent(QMouseEvent *event)
 {
     //Get coordinates
     int x = event->x();
     int y = event->y();

     //Add to the list
     QPointF q(x, y);
     points.push_back(q);

     //Repaint screen
     repaint();

 }

 void Draw::paintEvent(QPaintEvent *e)
 {
     QPainter qp(this);
     qp.begin(this);

     // Draw points
     for(int i=0; i< points.size(); i++)
     {
         qp.drawEllipse(points[i].x() - 3, points[i].y() - 3, 6, 6);
     }

     // Draw Ch
     qp.setPen(Qt::magenta);
     qp.drawPolygon(ch);
     qp.end();

     }

 std::vector<QPointF> Draw::generatePointsRandom(int n_points)
  {
      std::vector<QPointF> points;
      QPointF point;
      double x,y;

      for (int i = 0; i < n_points; i++)
      {
          x = rand() %700+15;
          y = rand() %700+15;
          point.setX(x);
          point.setY(y);
          points.push_back(point);

      }


      // Erase duplicit points
      std::sort( points.begin(), points.end(), SortbyX());

      for(int i = 1; i <= n_points; i++)
      {
          if ( (points[i].x() == points[i-1].x()) && (points[i].y() == points[i-1].y()) )
               points.erase(points.end());
      }

      return points;
  }

 std::vector<QPointF> Draw::generatePointsGrid(int n_points)
  {
      std::vector<QPointF> points;
      QPointF point;
      double x = 0;
      double y;

      while (x <= 700)
      {
        x += 700/sqrt(n_points);
        y = 0;

        while (y <= 700)
        {
                y += 700/sqrt(n_points);
                point.setX(x);
                point.setY(y);
                points.push_back(point);
        }
   }
      return points;
  }

 std::vector<QPointF> Draw::generatePointsSquare(int n_points)
  {
      std::vector<QPointF> points;
      QPointF point(15,15);
      double side = 1000000*700/(n_points/4);
      double x = 15;
      double y = 15;


      for(int i = 0;i < n_points/4;i++)
          {
              points.push_back(QPointF(point.x()+(i*(side/1000000)),point.y()));
              points.push_back(QPointF(point.x()+(700),point.y()+(i*(side/1000000))));
              points.push_back(QPointF(point.x()+(i*(side/1000000)),point.y()+(700)));
              points.push_back(QPointF(point.x(),point.y()+(i*(side/1000000))));
          }

      return points;
  }

 std::vector<QPointF> Draw::generatePointsCircle(int n_points)
  {
      std::vector<QPointF> points;
      QPointF point;

      QPointF center(365,365);
      double radius = 350;
      double x ,y;

      for (double angle=0; angle<=2*M_PI; angle+=(2*M_PI/n_points))
      {
        x = center.x() + radius*cos( angle );
        y = center.y() + radius*sin( angle );
        point.setX(x);
        point.setY(y);
        points.push_back(point);
      }

      return points;
  }

 std::vector<QPointF> Draw::generatePointsEllipse(int n_points)
  {
      std::vector<QPointF> points;
      QPointF point;

      QPointF center(365,365);
      double a = 350;
      double b = a/2;
      double x ,y;

      for (double angle=0; angle<=2*M_PI; angle+=(2*M_PI/n_points))
      {

        x = center.x() + a*cos( angle );
        y = center.y() + b*sin( angle );
        point.setX(x);
        point.setY(y);
        points.push_back(point);
      }

      return points;
  }
