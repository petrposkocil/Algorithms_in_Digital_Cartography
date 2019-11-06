#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <QtGui>


class Algorithms
{
public:
    Algorithms();
    static double getPointLineDistance(QPoint &q, QPoint &p1, QPoint &p2);
    static int getPointLinePosition(QPoint &q,QPoint &p1,QPoint &p2);
    static double getAngle2Vectors(QPoint &p1,QPoint &p2,QPoint &p3,QPoint &p4);
    static double getLength2Points(QPoint q, QPoint p){return sqrt( (q.x()-p.x())*(q.x()-p.x())+(q.y()-p.y())*(q.y()-p.y()) );}
    static QPolygon jarvisScan(std::vector<QPoint> &points);
    static QPolygon qHull(std::vector<QPoint> &points);
    static void qh(int s, int e, std::vector<QPoint> &points, QPolygon &ch);
    static QPolygon sweepLine(std::vector<QPoint> &points);
    static QPolygon strictlyCH(QPolygon ch);
};

#endif // ALGORITHMS_H
