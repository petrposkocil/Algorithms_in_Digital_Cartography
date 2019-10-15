#include "widget.h"
#include "ui_widget.h"
#include "algorithms.h"
#include "draw.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

// Button Clear - clear entire content of Qwidget - Canvas
void Widget::on_pushButton_3_clicked()
{
    ui->Canvas->clearCanvas();
}

// Activate/disble button Draw point Q
void Widget::on_pushButton_clicked()
{
    ui->Canvas->setDrawPoint();
}

// Analyze button - runs both algoritms based on the choice from combobox and visualise the result
void Widget::on_pushButton_2_clicked()
{
    qDebug() << "Analyze polygons ... " << endl;

    // Get point Q
    QPointF q = ui->Canvas->getPoint();

    // Get polygons one by one
    std::vector<int> res;

    // Compute result - position of point and polygon
    for(unsigned int i = 0; i < ui->Canvas->getPolygons().size(); i++)
    {
        QPolygonF pol = ui->Canvas->getPolygon(i);
       int result = ui->comboBox->currentIndex() == 0? Algorithms::getPositionWinding(q, pol) : Algorithms::getPositionRay(q, pol);

        res.push_back(result);
        ui->Canvas->setResult(res);
        qDebug() << "Result " << i << " is " << result;

    }
    ui->Canvas->repaint();

}

// Input path and import file
void Widget::on_importPolygons_clicked()
{
    QString path = QFileDialog::getOpenFileName(
                this,
                tr("Select file"),
                "/",
                "Text file (*.txt);;All files (*.*)");

    std::string path_utf8 = path.toUtf8().constData();
    QString msg;

    ui->Canvas->importPolygons(path_utf8);
}
