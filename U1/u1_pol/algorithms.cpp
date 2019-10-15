#include "algorithms.h"

Algorithms::Algorithms()
{

}

int Algorithms::getPositionWinding(QPointF q, QPolygonF pol)
{
       int n = pol.size();
       double sum_fi = 0.0;
       double eps = 1.0e-10;
       int k = 0;

       //Process all polygon segments
       for (int i = 0; i < n; i++)
       {
           // Solve point sigularity effect on the vertex
           if( fabs(q.x() - pol[i].x()) < eps && fabs(q.y() - pol[i].y()) < eps )
           {
               k = -1;
           }

           else
           {
                // Get angle
                double fi = get2LinesAngle(pol[i], q, pol[(i + 1) % n], q);

                // Get position
                int t = getPointLinePosition(q, pol[i], pol[(i + 1) % n]);

                // Check whether the point Q lies on the edge
                if(t == -2)
                    return 1;

                // Check whether the point Q lies in the left halfplane
                if(t > 0)
                    sum_fi += fi;

                // Check whether the point Q lies in the right half plane
                else
                    sum_fi -= fi;
           }
       }

    if(k == -1)
    {
        //Point q on the vertex
        return 1;
    }
    else
    {
       //Point q inside P
       if (fabs(fabs(sum_fi) - 360) < eps)
           return 1;

       //Point q outside P
       if (fabs(sum_fi) < eps)
           return 0;

       //something else ???
       else
           return -1;
    }
}

int Algorithms::getPointLinePosition(QPointF &q, QPointF &a, QPointF &b)
{
    // Thresholds
    double eps = 1.0e-8;
    double eps2 = 2.0;

    // Position between point and line
    double ux = b.x() - a.x();
    double uy = b.y() - a.y();
    double vx = q.x() - a.x();
    double vy = q.y() - a.y();

    // Determinant
    double t = (ux * vy - uy * vx);

    // Check whether the point Q lies in the left half plane
    if(t > eps)
        return 1;

    // Check whether the point Q lies in the right half plane
    if(t < -eps)
        return 0;

    // Check whether the point Q lies on the edge
    // Distance between point q, a, b
    double dist_qa = sqrt((vx * vx) + (vy * vy));
    double dist_qb = sqrt((q.x() - b.x()) * (q.x() - b.x()) + (q.y() - b.y()) * (q.y() - b.y()));
    double dist_ab = sqrt((ux * ux) + (uy * uy));
    double dist = dist_qa + dist_qb;

    if((fabs(dist - dist_ab)) <= eps2)
    {
        return -2;
    }

    return -1;
}

double Algorithms::get2LinesAngle(QPointF &p1,QPointF &p2,QPointF &p3, QPointF &p4)
{
    // Angle between two lines
    double ux = p2.x() - p1.x();
    double uy = p2.y() - p1.y();
    double vx = p4.x() - p3.x();
    double vy = p4.y() - p3.y();

    // Dot product
    double dot = ux * vx + uy * vy;

    // Norms of vectors
    double nu = sqrt(ux * ux + uy * uy);
    double nv = sqrt(vx * vx + vy * vy);

    // Result
    return fabs(acos(dot / (nu * nv))) * (180 / M_PI);
}

int Algorithms::getPositionRay(QPointF q, QPolygonF pol)
{
    double eps = 1.0e-10;               // Machine epsilon - threshold
    int k = 0;                          // Icrement number for result of the analysis
    int n = pol.size();

    double xir = pol[0].x() - q.x();
    double yir = pol[0].y() - q.y();

    for(int i = 1; i < n + 1; i++)
    {
        // Image coordinates reduced from origin [0,0] to Q[x,y]
        double xiir = pol[i % n].x() - q.x();
        double yiir = pol[i % n].y() - q.y();

        // Get distance between [xi, yi] and [xii, yii]
        double dist_i_ii = sqrt((xir - xiir) * (xir - xiir) + (yir - yiir) * (yir - yiir));

        // Get the addition of distance between [xi, yi] and Q, and [xiir, yiir] and q
        double dist_q = sqrt((xir * xir + yir * yir)) + sqrt((xiir * xiir + yiir * yiir));

        // Check whether the point Q lies on the edge
        if(fabs(dist_i_ii - dist_q) < eps)
        {
            return 1;
        }

        // Upper halfplane test
        if(((yiir > 0) && (yir <= 0)) || ((yir > 0) && (yiir <= 0)))
        {
            // Right halfplane test - suitable crossing
            double xm = (xiir * yir - xir * yiir)/(yiir - yir);

            if(xm > 0)
            {
                k++;
            }
        }

        xir = xiir;
        yir = yiir;
    }

    // 0 - point is outside; 1 - point is inside
    return k % 2;
}
