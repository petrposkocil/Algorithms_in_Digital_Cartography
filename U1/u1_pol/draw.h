#ifndef DRAW_H
#define DRAW_H

#include <QWidget>
#include <vector>
#include <fstream>
#include <string.h>
#include <QDebug>

class Draw : public QWidget
{
    Q_OBJECT

private:
    bool draw_point;
    QPointF q;
    QPolygonF pol;
    std::vector<QPolygonF> polygons;
    std::vector<int> result;

public:
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void setDrawPoint();
    QPointF getPoint() {return q;}
    QPolygonF getPolygon(unsigned int index){return polygons.at(index);}
    explicit Draw(QWidget *parent = nullptr);
    bool importPolygons(std::string &path);
    void clearCanvas();
    void setResult(std::vector<int> res){result = res;}
    std::vector<QPolygonF> getPolygons(){return polygons;}

signals:

public slots:
};

#endif // DRAW_H
