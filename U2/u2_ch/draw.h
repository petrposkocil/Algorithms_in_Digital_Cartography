#ifndef DRAW_H
#define DRAW_H

#include <QWidget>
#include <vector>

class Draw : public QWidget
{
    Q_OBJECT

private:
    std::vector<QPointF> points;
    QPolygonF ch;

public:
    explicit Draw(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *e);
    void clearCH(){ch.clear(); repaint();}
    void clearPoints(){points.clear(); repaint();}

    std::vector<QPointF> getPoints(){return points;}
    void setCH(QPolygonF &hull){ ch = hull;}

    // Generate and draw points
    static std::vector<QPointF>generatePointsRandom(int n_points);
    static std::vector<QPointF>generatePointsGrid(int n_points);
    static std::vector<QPointF>generatePointsSquare(int n_points);
    static std::vector<QPointF>generatePointsCircle(int n_points);
    static std::vector<QPointF>generatePointsEllipse(int n_points);
    void setPoints(std::vector<QPointF> gen_points){points = gen_points;}


signals:

public slots:
};

#endif // DRAW_H
