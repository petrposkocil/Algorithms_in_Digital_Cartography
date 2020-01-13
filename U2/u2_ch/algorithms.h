#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <QtGui>


class Algorithms
{
public:
    Algorithms();
    static double getPointLineDistance(QPointF &q, QPointF &p1, QPointF &p2);
    static int getPointLinePosition(QPointF &q,QPointF &p1,QPointF &p2);
    static double getAngle2Vectors(QPointF &p1,QPointF &p2,QPointF &p3,QPointF &p4);
    static double getLength2Points(QPointF q, QPointF p){return sqrt( (q.x()-p.x())*(q.x()-p.x())+(q.y()-p.y())*(q.y()-p.y()) );}
    static QPolygonF jarvisScan(std::vector<QPointF> &points);
    static QPolygonF qHull(std::vector<QPointF> &points);
    static void qh(int s, int e, std::vector<QPointF> &points, QPolygonF &ch);
    static QPolygonF sweepLine(std::vector<QPointF> &points);
    static QPolygonF strictlyCH(QPolygonF ch);
};

#endif // ALGORITHMS_H
