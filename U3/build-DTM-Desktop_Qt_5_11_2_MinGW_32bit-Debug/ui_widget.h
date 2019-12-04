/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "draw.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout;
    Draw *Canvas;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QPushButton *load;
    QComboBox *comboBox;
    QPushButton *pushButton_8;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QRadioButton *radioButton;
    QPushButton *pushButton_4;
    QSpacerItem *verticalSpacer_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_7;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *saveImage;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(800, 600);
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        Canvas = new Draw(Widget);
        Canvas->setObjectName(QStringLiteral("Canvas"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(Canvas->sizePolicy().hasHeightForWidth());
        Canvas->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(Canvas);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));

        verticalLayout->addLayout(verticalLayout_2);

        load = new QPushButton(Widget);
        load->setObjectName(QStringLiteral("load"));

        verticalLayout->addWidget(load);

        comboBox = new QComboBox(Widget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout->addWidget(comboBox);

        pushButton_8 = new QPushButton(Widget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        verticalLayout->addWidget(pushButton_8);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        lineEdit_2 = new QLineEdit(Widget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        verticalLayout->addWidget(lineEdit_2);

        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        lineEdit_3 = new QLineEdit(Widget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        verticalLayout->addWidget(lineEdit_3);

        radioButton = new QRadioButton(Widget);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout->addWidget(radioButton);

        pushButton_4 = new QPushButton(Widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        pushButton_5 = new QPushButton(Widget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        verticalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(Widget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        verticalLayout->addWidget(pushButton_6);

        pushButton_9 = new QPushButton(Widget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        verticalLayout->addWidget(pushButton_9);

        pushButton_10 = new QPushButton(Widget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));

        verticalLayout->addWidget(pushButton_10);

        pushButton_7 = new QPushButton(Widget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        verticalLayout->addWidget(pushButton_7);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        saveImage = new QPushButton(Widget);
        saveImage->setObjectName(QStringLiteral("saveImage"));

        verticalLayout->addWidget(saveImage);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "DIGITAL TERRAIN MODELer 1.0", nullptr));
        load->setText(QApplication::translate("Widget", "Load Point Data", nullptr));
        comboBox->setItemText(0, QString());
        comboBox->setItemText(1, QApplication::translate("Widget", "Hill", nullptr));
        comboBox->setItemText(2, QApplication::translate("Widget", "Valley", nullptr));
        comboBox->setItemText(3, QApplication::translate("Widget", "Saddle", nullptr));

        pushButton_8->setText(QApplication::translate("Widget", "Generate Points", nullptr));
        pushButton->setText(QApplication::translate("Widget", "Delaunay", nullptr));
        label->setText(QApplication::translate("Widget", "Lowest contour", nullptr));
        lineEdit->setText(QApplication::translate("Widget", "0", nullptr));
        label_2->setText(QApplication::translate("Widget", "Highest contour", nullptr));
        lineEdit_2->setText(QApplication::translate("Widget", "500", nullptr));
        label_3->setText(QApplication::translate("Widget", "Contour interval", nullptr));
        lineEdit_3->setText(QApplication::translate("Widget", "5", nullptr));
        radioButton->setText(QApplication::translate("Widget", "Contour Heights", nullptr));
        pushButton_4->setText(QApplication::translate("Widget", "Create contours", nullptr));
        pushButton_5->setText(QApplication::translate("Widget", "Analyze Slope", nullptr));
        pushButton_6->setText(QApplication::translate("Widget", "Analyze Aspect", nullptr));
        pushButton_9->setText(QApplication::translate("Widget", "1st Gradient Color", nullptr));
        pushButton_10->setText(QApplication::translate("Widget", "2nd Gradient Color", nullptr));
        pushButton_7->setText(QApplication::translate("Widget", "Analyze Hypsometry", nullptr));
        pushButton_2->setText(QApplication::translate("Widget", "Clear Points", nullptr));
        pushButton_3->setText(QApplication::translate("Widget", "Clear DT", nullptr));
        saveImage->setText(QApplication::translate("Widget", "Save Widget Content", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
