#ifndef DRAW_H
#define DRAW_H

#include <QWidget>
#include "qpointfb.h"
#include "edge.h"

class Draw : public QWidget
{
    Q_OBJECT
private:
    std::vector<QPointFB> a,b;
    std::vector<Edge> res;
    std::vector<QPolygonF> polygons;
    QPointF q;
    bool ab, ab_select, paint_active;

public:
    explicit Draw(QWidget *parent = nullptr);
    void changePolygon(){ab = !ab;}
    void changeImportedPolygon(){ab_select = !ab_select;}
    bool getSelectAB (){return ab_select;}
    void paintActive(){paint_active = !paint_active;}
    void setA (std::vector<QPointFB> &a_){a = a_;}
    void setB (std::vector<QPointFB> &b_){b = b_;}
    void setQ (QPointF q_) {q = q_;}
    void setRes (std::vector<Edge> res_){res = res_;}
    void setPolygons(std::vector<QPolygonF> polygons_){polygons = polygons_;}
    std::vector<QPointFB> getA(){return a;}
    std::vector<QPointFB> getB(){return b;}
    QPointF getQ (){return q;}
    std::vector<Edge> getRes(){return res;}
    std::vector<QPolygonF> getPolygons(){return polygons;}
    void clearResults() {res.clear();}
    void clearAll() {res.clear(); a.clear(); b.clear(); polygons.clear();}
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void drawPolygon(QPainter &painter, std::vector<QPointFB> &polygon);
    void importPolygons(std::string &path, std::vector<QPolygonF> &polygons,  QSizeF &canvas_size);

signals:

public slots:
};

#endif // DRAW_H
