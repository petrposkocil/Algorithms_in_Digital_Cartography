#include "widget.h"
#include "ui_widget.h"
#include "algorithms.h"
#include "types.h"
#include <fstream>
#include <QFileDialog>
#include <QColorDialog>
#include "draw.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    ui->Canvas->changePolygon();
}

void Widget::on_pushButton_2_clicked()
{
    //Get polygons
    std::vector<QPointFB> polA = ui->Canvas->getA();
    std::vector<QPointFB> polB = ui->Canvas->getB();

    //Perform Boolean operation
    TBooleanOperation oper = (TBooleanOperation)(ui->comboBox->currentIndex());
    std::vector<Edge> res = Algorithms::booleanOperations(polA, polB, oper);

    //Set results and update
    ui->Canvas->setRes(res);
    repaint();
}

void Widget::on_pushButton_3_clicked()
{
    ui->Canvas->clearResults();
    repaint();
}

void Widget::on_pushButton_4_clicked()
{
    ui->Canvas->clearAll();
    repaint();
}

void Widget::on_pushButton_5_clicked()
{
    std::vector<QPolygonF> polygons;
        QSizeF canvas_size = ui->Canvas->size();

        QString path = QFileDialog::getOpenFileName(this, tr("Select file"), "/", "Text file (*.txt);;All files (*.*)");
        std::string path_utf8 = path.toUtf8().constData();

        ui->Canvas->importPolygons(path_utf8, polygons, canvas_size);
        ui->Canvas->setPolygons(polygons);
        ui->Canvas->repaint();
}

void Widget::on_radioButton_clicked()
{
    ui->Canvas->paintActive();
}

void Widget::on_pushButton_6_clicked()
{
    ui->Canvas->changeImportedPolygon();
    bool a_or_b = ui->Canvas->getSelectAB();

    QColorDialog k;
    QColor ccc2(Qt::blue);
    QColor ccc1(Qt::green);
    QPalette pal = ui->pushButton_6->palette();
    if (a_or_b == true)
        pal.setColor(QPalette::Button, ccc1);
    else
        pal.setColor(QPalette::Button, ccc2);
    ui->pushButton_6->setAutoFillBackground(true);
    ui->pushButton_6->setPalette(pal);
    ui->pushButton_6->update();
}
