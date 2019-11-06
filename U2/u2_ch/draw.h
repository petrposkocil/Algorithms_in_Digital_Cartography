#ifndef DRAW_H
#define DRAW_H

#include <QWidget>
#include <vector>

class Draw : public QWidget
{
    Q_OBJECT

private:
    std::vector<QPoint> points;
    QPolygon ch;

public:
    explicit Draw(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *e);
    void clearCH(){ch.clear(); repaint();}
    void clearPoints(){points.clear(); repaint();}

    std::vector<QPoint> getPoints(){return points;}
    void setCH(QPolygon &hull){ ch = hull;}

    // Generate and draw points
    static std::vector<QPoint>generatePointsRandom(int n_points);
    static std::vector<QPoint>generatePointsGrid(int n_points);
    static std::vector<QPoint>generatePointsSquare(int n_points);
    static std::vector<QPoint>generatePointsCircle(int n_points);
    static std::vector<QPoint>generatePointsEllipse(int n_points);
    void setPoints(std::vector<QPoint> gen_points){points = gen_points;}


signals:

public slots:
};

#endif // DRAW_H
