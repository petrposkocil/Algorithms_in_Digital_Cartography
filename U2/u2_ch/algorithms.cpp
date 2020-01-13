#include "algorithms.h"
#include <cmath>
#include "sortbyy.h"
#include "sortbyx.h"
#include <vector>

Algorithms::Algorithms()
{

}

double Algorithms::getPointLineDistance(QPointF &q, QPointF &p1, QPointF &p2){
    // Calculate point and line distance
    double numerator = q.x() * (p1.y() - p2.y()) + p1.x() * (p2.y() - q.y()) + p2.x() * (q.y() - p1.y());
    double dx = p2.x() - p1.x();
    double dy = p2.y() - p1.y();
    double denumenator = sqrt(dx * dx + dy * dy);

    double dist = fabs(numerator)/denumenator;
    return dist;
}

int Algorithms::getPointLinePosition(QPointF &q,QPointF &p1,QPointF &p2)
{
    double eps = 1.0e-10;

    //get vectors
    double ux = p2.x() - p1.x();
    double uy = p2.y() - p1.y();
    double vx = q.x() - p1.x();
    double vy = q.y() - p1.y();

    //get cross product
    double t = ux*vy - uy*vx;

    //Point in the left half plane
    if(t > eps)
        return 1;

    //Point in the right half plane
    if(t < -eps)
        return 0;

    //Point on the line
    return -1;
}

double Algorithms::getAngle2Vectors(QPointF &p1, QPointF &p2, QPointF &p3, QPointF &p4)
{
    // Calculate Vector betwen 2 vectors.
    double ux = p2.x() - p1.x();
    double uy = p2.y() - p1.y();

    double vx = p4.x() - p3.x();
    double vy = p4.y() - p3.y();

    // Norms
    double nu = sqrt(ux * ux + uy * uy);
    double nv = sqrt(vx * vx + vy * vy);

    // Dot product
    double scalar = ux * vx + uy * vy;

    double angle = fabs(acos(scalar/(nu*nv)));
    return angle;
}

QPolygonF Algorithms::jarvisScan(std::vector<QPointF> &points)
{
    double eps = 1e-6;
    double min_dist = eps;

    // Convex hull
    QPolygonF ch;

    // Sort points by Y
    std::sort(points.begin(), points.end(), SortbyY());
    QPointF q=points[0];
    QPointF r(q.x()-1,q.y());

    // Initialize points pj, pjj
    QPointF pj = q;
    QPointF pjj = r;

    // Add to CH
    ch.push_back(q);

    // Find points of CH
    do
    {
        double om_max = 0;
        int i_max = -1;

        // Find point of CH
        for(int i = 0; i < points.size(); i++)
        {
            double omega = getAngle2Vectors(pj, pjj, pj, points[i]);

            // Actualize maximum.
            if (omega > om_max)
            {
                om_max = omega;
                i_max = i;
            }

            // Singularity of colinear points - reduction
            else if (fabs(omega-om_max) < eps)
            {
                double dist = getLength2Points(pj, points[i]);

                if(min_dist > dist)
                {
                    min_dist = dist;
                    i_max = i;
                    om_max = omega;
                }
            }
        }

        // Add point to the convex hull
        ch.push_back(points[i_max]);

        // Change index
        pjj = pj;
        pj = points[i_max];

    } while (!(pj == q));

    // Strictly convex hull
    strictlyCH(ch);

    return ch;

}

QPolygonF Algorithms::qHull(std::vector<QPointF> &points)
{
    // Convex Hull by quick hull method
    QPolygonF ch;
    std::vector<QPointF> upoints, lpoints;

    // Sort by X.
    std::sort(points.begin(), points.end(), SortbyX());
    QPointF q1 = points[0];
    QPointF q3 = points.back();

    // Add q1, q3 to upoints, lpoints
    upoints.push_back(q1);
    upoints.push_back(q3);

    lpoints.push_back(q1);
    lpoints.push_back(q3);

    // Split to upoints / lpoints
    for(unsigned int i=0; i < points.size();i++){

        // Add to the upper part
        if(getPointLinePosition(points[i], q1, q3) == 1)
            upoints.push_back(points[i]);

        // Add to the lower part
        else if (getPointLinePosition(points[i], q1, q3) == 0)
            lpoints.push_back(points[i]);
    }

    // Call recursive function
    ch.push_back(q3);
    qh(1, 0, upoints, ch);
    ch.push_back(q1);
    qh(0, 1, lpoints, ch);

    // Strictly convex hull
    strictlyCH(ch);

    return ch;
}

void Algorithms::qh(int s, int e, std::vector<QPointF> &points, QPolygonF &ch){

    // Recursive procedure
    int i_max = -1;
    double d_max = 0;

    // Browse all points
    for (int i = 2; i < points.size(); i++)
    {
       // Is the point in the right half plane
        if (getPointLinePosition(points[i], points[s], points[e]) == 0)
        {
            double d = getPointLineDistance(points[i], points[s], points[e]);

            // Actualization of d_max
            if(d > d_max){
                d_max = d;
                i_max = i;
            }
        }
    }

    // Suitable point has been found
    if(i_max != -1)
    {
        qh(s, i_max, points, ch);
        ch.push_back(points[i_max]);
        qh(i_max, e, points, ch);
    }

}

QPolygonF Algorithms::sweepLine(std::vector<QPointF> &points)
{

    //create convex hull using the Sweep line procedure
        QPolygonF ch;

        //sort by x coord asc
        std::sort(points.begin(), points.end(), SortbyX());

        //delete duplicit points on sorted data
        std::vector<QPointF> pointsWithRemovedDuplicit;
        for(unsigned int i =0; i<points.size() - 1; i++){
            if((points[i].x()!=points[i+1].x()) || (points[i].y()!=points[i+1].y())  ){
                pointsWithRemovedDuplicit.push_back(points[i]);
            }
        }
        pointsWithRemovedDuplicit.push_back(points[points.size() - 1]);

        points = pointsWithRemovedDuplicit;

        //create list of predecessors (p) and successors (n)
        std::vector< unsigned int> p(points.size()), n(points.size());

        //create initial bi-angle from first 2 points
        n[0] = 1;
        n[1] = 0;

        p[0] = 1;
        p[1] = 0;

        for(unsigned int i = 2; i < points.size(); i++)
        {
            //does new point lie on upper/lower halfplane?
            //link i with predecessor/succesor

            if(getPointLinePosition(points[i], points[p[i-1]], points[i-1]) == 1)
            {
                p[i] = i-1;
                n[i] = n[i-1];
            }
            else
            {
                p[i] = p[i-1];
                n[i] = i-1;
            }

            //link predecessor/successor with i
            n[p[i]] = i;
            p[n[i]] = i;

            //fix upper tangent
            while(getPointLinePosition(points[n[n[i]]], points[i], points[n[i]]) == 0)
            {
                p[n[n[i]]] = i;
                n[i] = n[n[i]];

            }

            //fix lower tangent
            while(getPointLinePosition(points[p[p[i]]], points[i], points[p[i]]) == 1)
            {
                n[p[p[i]]] = i;
                p[i] = p[p[i]];
            }
        }

        //add points to poly_ch
        ch.push_back(points[0]);

        unsigned int index = n[0];

        while(index != 0)
        {
            ch.push_back(points[index]);
            index = n[index];
        }

        strictlyCH(ch);

        return ch;
    }


QPolygonF Algorithms::strictlyCH(QPolygonF ch)
{

    // Delete points on the same line
    for(int i=0; i<(ch.size()-2); i++){
        if(getPointLinePosition(ch[i+2], ch[i], ch[i+1]) == -1){
            ch.remove(i+1);
            i--;
        }
    }

    return ch;
}
