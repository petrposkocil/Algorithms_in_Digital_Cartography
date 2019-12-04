#include "widget.h"
#include "ui_widget.h"
#include "algorithms.h"
#include "triangle.h"
#include "draw.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QColorDialog>
#include <QDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    z_min = 0;
    z_max = 1000;
    dz = 10;

    //Set initial values
    ui->lineEdit->setText(QString::number(z_min));
    ui->lineEdit_2->setText(QString::number(z_max));
    ui->lineEdit_3->setText(QString::number(dz));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    ui->Canvas->clearDT();
    std::vector<QPoint3D> points = ui->Canvas->getPoints();

    //Construct DT
    std::vector<Edge> dt = Algorithms::DT(points);
    ui->Canvas->setDt(dt);

    repaint();
}

void Widget::on_pushButton_2_clicked()
{
    ui->Canvas->clearPoints();
    repaint();
}

void Widget::on_pushButton_3_clicked()
{
    ui->Canvas->clearDT();
    ui->Canvas->clearDTM();
    ui->Canvas->clearContours();
    repaint();
}

void Widget::on_pushButton_4_clicked()
{
    std::vector<Edge> dt;

    //Create triangulation
    if (ui->Canvas->getDtSize() == 0)
    {
        std::vector<QPoint3D> points=ui->Canvas->getPoints();
        dt = Algorithms::DT(points);
        ui->Canvas->setDt(dt);
    }

    //Triangulation has been created
    else
    {
        dt = ui->Canvas->getDt();
    }

    //Create contour lines
    std::vector<Edge> contours = Algorithms::createContourLines(dt, z_min, z_max, dz);
    ui->Canvas->setContours(contours);

    //Create main contour lines
    std::vector<Edge> mainContours = Algorithms::createContourLines(dt, z_min, z_max, 5*dz);
    ui->Canvas->setMainContours(mainContours);


    repaint();
}

void Widget::on_lineEdit_editingFinished()
{
    //Set z_min
    z_min = ui->lineEdit->text().toDouble();
}

void Widget::on_lineEdit_2_editingFinished()
{
    //Set z_max
    z_max = ui->lineEdit_2->text().toDouble();
}

void Widget::on_lineEdit_3_editingFinished()
{
    //Set dz
    dz = ui->lineEdit_3->text().toDouble();
}

//Slope
void Widget::on_pushButton_5_clicked()
{
    //Set draw mehtod for slope
    ui->Canvas->setMethod(0);

    std::vector<Edge> dt;

    //Create triangulation
    if (ui->Canvas->getDtSize() == 0)
    {
        std::vector<QPoint3D> points=ui->Canvas->getPoints();
        dt = Algorithms::DT(points);
        ui->Canvas->setDt(dt);
    }

    //Triangulation has been created
    else
    {
        dt = ui->Canvas->getDt();
    }

    //Analyze DTM
    std::vector<Triangle> dtm = Algorithms::analyzeDTM(dt);
    ui->Canvas->setDTM(dtm);
    repaint();
}

//Aspect
void Widget::on_pushButton_6_clicked()
{
    //Set draw mehtod for aspect
    ui->Canvas->setMethod(1);

    std::vector<Edge> dt;

    //Create triangulation
    if (ui->Canvas->getDtSize() == 0)
    {
        std::vector<QPoint3D> points=ui->Canvas->getPoints();
        dt = Algorithms::DT(points);
        ui->Canvas->setDt(dt);
    }

    //Triangulation has been created
    else
    {
        dt = ui->Canvas->getDt();
    }

    //Analyze DTM
    std::vector<Triangle> dtm = Algorithms::analyzeDTM(dt);
    ui->Canvas->setDTM(dtm);
    repaint();
}

// Hypsometry
void Widget::on_pushButton_7_clicked()
{
    //Set draw mehtod for aspect
    ui->Canvas->setMethod(2);

    std::vector<Edge> dt;

    //Create triangulation
    if (ui->Canvas->getDtSize() == 0)
    {
        std::vector<QPoint3D> points=ui->Canvas->getPoints();
        dt = Algorithms::DT(points);
        ui->Canvas->setDt(dt);
    }

    //Triangulation has been created
    else
    {
        dt = ui->Canvas->getDt();
    }

    //Analyze DTM
    std::vector<Triangle> dtm = Algorithms::analyzeDTM(dt);
    ui->Canvas->setDTM(dtm);
    repaint();
}

void Widget::on_load_clicked()
{
    std::vector<QPoint3D> points;
    QSizeF canvas_size = ui->Canvas->size();
    QString path = QFileDialog::getOpenFileName(this,tr("Select file"),"/","Text file (*.txt);;All files (*.*)");
    std::string path_utf8 = path.toUtf8().constData();

    QColor def1(128,1,1);
    ui->Canvas->setColor1(def1);
    QColor def2(254,248,220);
    ui->Canvas->setColor2(def2);

    Draw::importPoints(path_utf8, points,canvas_size, z_min, z_max);

    ui->Canvas->setPoints(points);
    ui->Canvas->repaint();

}

void Widget::on_saveImage_clicked()
{
    QPixmap pixmap(this->size());
    this->render(&pixmap);
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),"/home/WidgetContent.jpg",tr("Images (*.jpg)"));
    pixmap.save(fileName);
}

void Widget::on_radioButton_clicked(bool checked)
{
    if (checked == TRUE)
    {
        ui->Canvas->setContourHeights(TRUE);
        ui->Canvas->repaint();    }
    else
        ui->Canvas->setContourHeights(FALSE);
        ui->Canvas->repaint();
}

void Widget::on_pushButton_8_clicked()
{
    std::vector<QPoint3D> points;
    QSizeF canvas_size = ui->Canvas->size();

    QColor def1(128,1,1);
    ui->Canvas->setColor1(def1);
    QColor def2(254,248,220);
    ui->Canvas->setColor2(def2);

    if (ui->comboBox->currentIndex() == 1)
    {
        points = Draw::generateTerrainHill(canvas_size, z_min, z_max);
    }
    if (ui->comboBox->currentIndex() == 2)
    {
        points = Draw::generateValley(canvas_size, z_min, z_max);
    }
    if (ui->comboBox->currentIndex() == 3)
    {
        points = Draw::generateSaddle(canvas_size, z_min, z_max);
    }
    ui->Canvas->setPoints(points);
    ui->Canvas->repaint();
}

void Widget::on_pushButton_9_clicked()
{
    //Set the first gradient color
    QColorDialog k;
    QColor ccc1 = k.getColor();
    ui->Canvas->setColor1(ccc1);
    QPalette pal = ui->pushButton_9->palette();
    pal.setColor(QPalette::Button, ccc1);
    ui->pushButton_9->setAutoFillBackground(true);
    ui->pushButton_9->setPalette(pal);
    ui->pushButton_9->update();
}

void Widget::on_pushButton_10_clicked()
{
    //Set the first gradient color
    QColorDialog l;
    QColor ccc2 = l.getColor();
    ui->Canvas->setColor2(ccc2);
    QPalette pal2 = ui->pushButton_10->palette();
    pal2.setColor(QPalette::Button, ccc2);
    ui->pushButton_10->setAutoFillBackground(true);
    ui->pushButton_10->setPalette(pal2);
    ui->pushButton_10->update();
}
