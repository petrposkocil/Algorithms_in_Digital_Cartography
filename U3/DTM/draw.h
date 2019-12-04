#ifndef DRAW_H
#define DRAW_H

#include <QWidget>
#include <vector>
#include "qpoint3d.h"
#include "edge.h"
#include "triangle.h"
#include <QColorDialog>
#include <QLabel>



class Draw : public QWidget
{
    Q_OBJECT
private:
    std::vector<QPoint3D> points;
    std::vector<Edge> dt;
    std::vector<Edge> contours, mainContours;
    std::vector<Triangle> dtm;
    int method;
    bool cont_heights_vsible = FALSE;
    QColor ccc1;
    QColor ccc2;

public:
    explicit Draw(QWidget *parent = nullptr);
    void setPoints(std::vector<QPoint3D> &points_){points=points_;}
    std::vector<Edge>& getDt() {return dt;}
    void setDt(std::vector<Edge> &dt_){dt=dt_;}
    void setContours(std::vector<Edge> &contours_){contours=contours_;}
    void setMainContours(std::vector<Edge> &mainContours_){mainContours=mainContours_;}
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    std::vector<QPoint3D> getPoints(){return points;}
    void clearPoints(){points.clear(); }
    void clearDT(){dt.clear();}
    void clearDTM(){dtm.clear();}
    void clearContours(){contours.clear(); mainContours.clear();}
    int getDtSize(){return dt.size();}
    void setDTM(std::vector<Triangle> & dtm_){dtm = dtm_;}
    void setMethod(int method_){method = method_;}
    void setContourHeights(bool cont_heights_vsible_){cont_heights_vsible = cont_heights_vsible_;}
    static void importPoints(std::string &path, std::vector<QPoint3D> &points,  QSizeF &canvas_size, double &z_min, double &z_max);
    void drawRotatedText(QPainter* painter, float degrees, double x, double y, QString &text);
    std::vector<int> generateColor(int &coeficient);
    static std::vector<QPoint3D> generateTerrainHill(QSizeF &canvas_size, double &z_min, double &z_max);
    static std::vector<QPoint3D> generateValley(QSizeF &canvas_size, double &z_min, double &z_max);
    static std::vector<QPoint3D> generateSaddle(QSizeF &canvas_size, double &z_min, double &z_max);
    void setColor1(QColor ccc1_) {ccc1 = ccc1_;}
    QColor getColor1(){return ccc1;}
    void setColor2(QColor ccc2_) {ccc2 = ccc2_;}
    QColor getColor2(){return ccc2;}

signals:

public slots:
};

#endif // DRAW_H
