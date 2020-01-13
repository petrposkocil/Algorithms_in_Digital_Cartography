#include "widget.h"
#include "ui_widget.h"
#include "algorithms.h"
#include <draw.h>
#include <time.h>
#include <QtDebug>
#include <QMessageBox>


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
    //Create convex hull
    QPolygonF ch;
    std::vector<QPointF> points = ui->Canvas->getPoints();
    std::vector<double> timesss;

    double start = clock();

    //Create CH
    if (ui->comboBox->currentIndex() == 0)
        ch = Algorithms::jarvisScan(points);
    else if(ui->comboBox->currentIndex() == 1)
        ch = Algorithms::qHull(points);
    else
        ch = Algorithms::sweepLine(points);

    // Time test
    double end = clock();
    double time = ((double)(end - start)) / CLOCKS_PER_SEC;
    QString t = QString::number(time);
    qDebug() << "Duration in [s]: \n" << time;
    ui->time_c->setText(t);
    ui->listWidget->addItem(t);
    QMessageBox msgBox;
    if (ui->listWidget->count() == 10)
    {
        msgBox.setText("You already ran the test 10 time.\n See the list of durations.");
        msgBox.exec();
    }

    //Draw
    ui->Canvas->setCH(ch);
    repaint();
}

void Widget::on_pushButton_2_clicked()
{
    ui->Canvas->clearPoints();
}

void Widget::on_pushButton_3_clicked()
{
    ui->Canvas->clearCH();
    ui->listWidget->clear();
}

void Widget::on_generate_clicked()
{
    int n_points;
    std::vector<QPointF> points;

    if (ui->gen_pattern->currentIndex() == 0)
    {
        if (ui->comboBox_2->currentIndex() == 0)
            points = Draw::generatePointsRandom(1000);
        else if (ui->comboBox_2->currentIndex() == 1)
            points = Draw::generatePointsRandom(5000);
        else if (ui->comboBox_2->currentIndex() == 2)
            points = Draw::generatePointsRandom(10000);
        else if (ui->comboBox_2->currentIndex() == 3)
            points = Draw::generatePointsRandom(25000);
        else if (ui->comboBox_2->currentIndex() == 4)
            points = Draw::generatePointsRandom(50000);
        else if (ui->comboBox_2->currentIndex() == 5)
            points = Draw::generatePointsRandom(75000);
        else if (ui->comboBox_2->currentIndex() == 6)
            points = Draw::generatePointsRandom(100000);
        else if (ui->comboBox_2->currentIndex() == 7)
            points = Draw::generatePointsRandom(250000);
        else if (ui->comboBox_2->currentIndex() == 8)
            points = Draw::generatePointsRandom(500000);
        else if (ui->comboBox_2->currentIndex() == 9)
            points = Draw::generatePointsRandom(750000);
        else if (ui->comboBox_2->currentIndex() == 10)
            points = Draw::generatePointsRandom(1000000);
    }

    if (ui->gen_pattern->currentIndex() == 1)
    {
        if (ui->comboBox_2->currentIndex() == 0)
            points = Draw::generatePointsGrid(1000);
        else if (ui->comboBox_2->currentIndex() == 1)
            points = Draw::generatePointsGrid(5000);
        else if (ui->comboBox_2->currentIndex() == 2)
            points = Draw::generatePointsGrid(10000);
        else if (ui->comboBox_2->currentIndex() == 3)
            points = Draw::generatePointsGrid(25000);
        else if (ui->comboBox_2->currentIndex() == 4)
            points = Draw::generatePointsGrid(50000);
        else if (ui->comboBox_2->currentIndex() == 5)
            points = Draw::generatePointsGrid(75000);
        else if (ui->comboBox_2->currentIndex() == 6)
            points = Draw::generatePointsGrid(100000);
        else if (ui->comboBox_2->currentIndex() == 7)
            points = Draw::generatePointsGrid(250000);
        else if (ui->comboBox_2->currentIndex() == 8)
            points = Draw::generatePointsGrid(500000);
        else if (ui->comboBox_2->currentIndex() == 9)
            points = Draw::generatePointsGrid(750000);
        else if (ui->comboBox_2->currentIndex() == 10)
            points = Draw::generatePointsGrid(1000000);
    }

    if (ui->gen_pattern->currentIndex() == 2)
    {
        if (ui->comboBox_2->currentIndex() == 0)
            points = Draw::generatePointsSquare(1000);
        else if (ui->comboBox_2->currentIndex() == 1)
            points = Draw::generatePointsSquare(5000);
        else if (ui->comboBox_2->currentIndex() == 2)
            points = Draw::generatePointsSquare(10000);
        else if (ui->comboBox_2->currentIndex() == 3)
            points = Draw::generatePointsSquare(25000);
        else if (ui->comboBox_2->currentIndex() == 4)
            points = Draw::generatePointsSquare(50000);
        else if (ui->comboBox_2->currentIndex() == 5)
            points = Draw::generatePointsSquare(75000);
        else if (ui->comboBox_2->currentIndex() == 6)
            points = Draw::generatePointsSquare(100000);
        else if (ui->comboBox_2->currentIndex() == 7)
            points = Draw::generatePointsSquare(250000);
        else if (ui->comboBox_2->currentIndex() == 8)
            points = Draw::generatePointsSquare(500000);
        else if (ui->comboBox_2->currentIndex() == 9)
            points = Draw::generatePointsSquare(750000);
        else if (ui->comboBox_2->currentIndex() == 10)
            points = Draw::generatePointsSquare(1000000);
    }

    if (ui->gen_pattern->currentIndex() == 3)
    {
        if (ui->comboBox_2->currentIndex() == 0)
            points = Draw::generatePointsCircle(1000);
        else if (ui->comboBox_2->currentIndex() == 1)
            points = Draw::generatePointsCircle(5000);
        else if (ui->comboBox_2->currentIndex() == 2)
            points = Draw::generatePointsCircle(10000);
        else if (ui->comboBox_2->currentIndex() == 3)
            points = Draw::generatePointsCircle(25000);
        else if (ui->comboBox_2->currentIndex() == 4)
            points = Draw::generatePointsCircle(50000);
        else if (ui->comboBox_2->currentIndex() == 5)
            points = Draw::generatePointsCircle(75000);
        else if (ui->comboBox_2->currentIndex() == 6)
            points = Draw::generatePointsCircle(100000);
        else if (ui->comboBox_2->currentIndex() == 7)
            points = Draw::generatePointsCircle(250000);
        else if (ui->comboBox_2->currentIndex() == 8)
            points = Draw::generatePointsCircle(500000);
        else if (ui->comboBox_2->currentIndex() == 9)
            points = Draw::generatePointsCircle(750000);
        else if (ui->comboBox_2->currentIndex() == 10)
            points = Draw::generatePointsCircle(1000000);
    }

    if (ui->gen_pattern->currentIndex() == 4)
    {
        if (ui->comboBox_2->currentIndex() == 0)
            points = Draw::generatePointsEllipse(1000);
        else if (ui->comboBox_2->currentIndex() == 1)
            points = Draw::generatePointsEllipse(5000);
        else if (ui->comboBox_2->currentIndex() == 2)
            points = Draw::generatePointsEllipse(10000);
        else if (ui->comboBox_2->currentIndex() == 3)
            points = Draw::generatePointsEllipse(25000);
        else if (ui->comboBox_2->currentIndex() == 4)
            points = Draw::generatePointsEllipse(50000);
        else if (ui->comboBox_2->currentIndex() == 5)
            points = Draw::generatePointsEllipse(75000);
        else if (ui->comboBox_2->currentIndex() == 6)
            points = Draw::generatePointsEllipse(100000);
        else if (ui->comboBox_2->currentIndex() == 7)
            points = Draw::generatePointsEllipse(250000);
        else if (ui->comboBox_2->currentIndex() == 8)
            points = Draw::generatePointsEllipse(500000);
        else if (ui->comboBox_2->currentIndex() == 9)
            points = Draw::generatePointsEllipse(750000);
        else if (ui->comboBox_2->currentIndex() == 10)
            points = Draw::generatePointsEllipse(1000000);
    }

    //Draw
    ui->Canvas->setPoints(points);
    repaint();
}

//test

void Widget::on_pushButton_4_clicked()
{

    do{
    int n_points;
    std::vector<QPointF> points;

    if (ui->gen_pattern->currentIndex() == 0)
    {
        if (ui->comboBox_2->currentIndex() == 0)
            points = Draw::generatePointsRandom(1000);
        else if (ui->comboBox_2->currentIndex() == 1)
            points = Draw::generatePointsRandom(5000);
        else if (ui->comboBox_2->currentIndex() == 2)
            points = Draw::generatePointsRandom(10000);
        else if (ui->comboBox_2->currentIndex() == 3)
            points = Draw::generatePointsRandom(25000);
        else if (ui->comboBox_2->currentIndex() == 4)
            points = Draw::generatePointsRandom(50000);
        else if (ui->comboBox_2->currentIndex() == 5)
            points = Draw::generatePointsRandom(75000);
        else if (ui->comboBox_2->currentIndex() == 6)
            points = Draw::generatePointsRandom(100000);
        else if (ui->comboBox_2->currentIndex() == 7)
            points = Draw::generatePointsRandom(250000);
        else if (ui->comboBox_2->currentIndex() == 8)
            points = Draw::generatePointsRandom(500000);
        else if (ui->comboBox_2->currentIndex() == 9)
            points = Draw::generatePointsRandom(750000);
        else if (ui->comboBox_2->currentIndex() == 10)
            points = Draw::generatePointsRandom(1000000);
    }

    if (ui->gen_pattern->currentIndex() == 1)
    {
        if (ui->comboBox_2->currentIndex() == 0)
            points = Draw::generatePointsGrid(1000);
        else if (ui->comboBox_2->currentIndex() == 1)
            points = Draw::generatePointsGrid(5000);
        else if (ui->comboBox_2->currentIndex() == 2)
            points = Draw::generatePointsGrid(10000);
        else if (ui->comboBox_2->currentIndex() == 3)
            points = Draw::generatePointsGrid(25000);
        else if (ui->comboBox_2->currentIndex() == 4)
            points = Draw::generatePointsGrid(50000);
        else if (ui->comboBox_2->currentIndex() == 5)
            points = Draw::generatePointsGrid(75000);
        else if (ui->comboBox_2->currentIndex() == 6)
            points = Draw::generatePointsGrid(100000);
        else if (ui->comboBox_2->currentIndex() == 7)
            points = Draw::generatePointsGrid(250000);
        else if (ui->comboBox_2->currentIndex() == 8)
            points = Draw::generatePointsGrid(500000);
        else if (ui->comboBox_2->currentIndex() == 9)
            points = Draw::generatePointsGrid(750000);
        else if (ui->comboBox_2->currentIndex() == 10)
            points = Draw::generatePointsGrid(1000000);
    }

    if (ui->gen_pattern->currentIndex() == 2)
    {
        if (ui->comboBox_2->currentIndex() == 0)
            points = Draw::generatePointsSquare(1000);
        else if (ui->comboBox_2->currentIndex() == 1)
            points = Draw::generatePointsSquare(5000);
        else if (ui->comboBox_2->currentIndex() == 2)
            points = Draw::generatePointsSquare(10000);
        else if (ui->comboBox_2->currentIndex() == 3)
            points = Draw::generatePointsSquare(25000);
        else if (ui->comboBox_2->currentIndex() == 4)
            points = Draw::generatePointsSquare(50000);
        else if (ui->comboBox_2->currentIndex() == 5)
            points = Draw::generatePointsSquare(75000);
        else if (ui->comboBox_2->currentIndex() == 6)
            points = Draw::generatePointsSquare(100000);
        else if (ui->comboBox_2->currentIndex() == 7)
            points = Draw::generatePointsSquare(250000);
        else if (ui->comboBox_2->currentIndex() == 8)
            points = Draw::generatePointsSquare(500000);
        else if (ui->comboBox_2->currentIndex() == 9)
            points = Draw::generatePointsSquare(750000);
        else if (ui->comboBox_2->currentIndex() == 10)
            points = Draw::generatePointsSquare(1000000);
    }

    if (ui->gen_pattern->currentIndex() == 3)
    {
        if (ui->comboBox_2->currentIndex() == 0)
            points = Draw::generatePointsCircle(1000);
        else if (ui->comboBox_2->currentIndex() == 1)
            points = Draw::generatePointsCircle(5000);
        else if (ui->comboBox_2->currentIndex() == 2)
            points = Draw::generatePointsCircle(10000);
        else if (ui->comboBox_2->currentIndex() == 3)
            points = Draw::generatePointsCircle(25000);
        else if (ui->comboBox_2->currentIndex() == 4)
            points = Draw::generatePointsCircle(50000);
        else if (ui->comboBox_2->currentIndex() == 5)
            points = Draw::generatePointsCircle(75000);
        else if (ui->comboBox_2->currentIndex() == 6)
            points = Draw::generatePointsCircle(100000);
        else if (ui->comboBox_2->currentIndex() == 7)
            points = Draw::generatePointsCircle(250000);
        else if (ui->comboBox_2->currentIndex() == 8)
            points = Draw::generatePointsCircle(500000);
        else if (ui->comboBox_2->currentIndex() == 9)
            points = Draw::generatePointsCircle(750000);
        else if (ui->comboBox_2->currentIndex() == 10)
            points = Draw::generatePointsCircle(1000000);
    }

    if (ui->gen_pattern->currentIndex() == 4)
    {
        if (ui->comboBox_2->currentIndex() == 0)
            points = Draw::generatePointsEllipse(1000);
        else if (ui->comboBox_2->currentIndex() == 1)
            points = Draw::generatePointsEllipse(5000);
        else if (ui->comboBox_2->currentIndex() == 2)
            points = Draw::generatePointsEllipse(10000);
        else if (ui->comboBox_2->currentIndex() == 3)
            points = Draw::generatePointsEllipse(25000);
        else if (ui->comboBox_2->currentIndex() == 4)
            points = Draw::generatePointsEllipse(50000);
        else if (ui->comboBox_2->currentIndex() == 5)
            points = Draw::generatePointsEllipse(75000);
        else if (ui->comboBox_2->currentIndex() == 6)
            points = Draw::generatePointsEllipse(100000);
        else if (ui->comboBox_2->currentIndex() == 7)
            points = Draw::generatePointsEllipse(250000);
        else if (ui->comboBox_2->currentIndex() == 8)
            points = Draw::generatePointsEllipse(500000);
        else if (ui->comboBox_2->currentIndex() == 9)
            points = Draw::generatePointsEllipse(750000);
        else if (ui->comboBox_2->currentIndex() == 10)
            points = Draw::generatePointsEllipse(1000000);
    }

    //Draw
    ui->Canvas->setPoints(points);
    repaint();

    //Create convex hull
    QPolygonF ch;
    std::vector<QPointF> points2 = ui->Canvas->getPoints();
    std::vector<double> timesss;

    double start = clock();

    //Create CH
    if (ui->comboBox->currentIndex() == 0)
        ch = Algorithms::jarvisScan(points2);
    else if(ui->comboBox->currentIndex() == 1)
        ch = Algorithms::qHull(points2);
    else
        ch = Algorithms::sweepLine(points2);

    // Time test
    double end = clock();
    double time = ((double)(end - start)) / CLOCKS_PER_SEC;
    QString t = QString::number(time);
    qDebug() << "Duration in [s]: \n" << time;
    ui->time_c->setText(t);
    ui->listWidget->addItem(t);
    QMessageBox msgBox;
    if (ui->listWidget->count() == 10)
    {
        msgBox.setText("You already ran the test 10 time.\n See the list of durations.");
        msgBox.exec();
    }

    //Draw
    ui->Canvas->setCH(ch);
    repaint();
    }while(ui->listWidget->count() < 10);
}
