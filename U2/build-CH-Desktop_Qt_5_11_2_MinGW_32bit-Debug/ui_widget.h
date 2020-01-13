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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
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
    QLabel *label_2;
    QComboBox *comboBox_2;
    QLabel *label_4;
    QComboBox *gen_pattern;
    QPushButton *generate;
    QSpacerItem *verticalSpacer_3;
    QLabel *label;
    QComboBox *comboBox;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QLabel *label_3;
    QLabel *time_c;
    QListWidget *listWidget;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1000, 762);
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        Canvas = new Draw(Widget);
        Canvas->setObjectName(QStringLiteral("Canvas"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(Canvas->sizePolicy().hasHeightForWidth());
        Canvas->setSizePolicy(sizePolicy);
        Canvas->setMinimumSize(QSize(600, 600));

        horizontalLayout->addWidget(Canvas);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        comboBox_2 = new QComboBox(Widget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        verticalLayout->addWidget(comboBox_2);

        label_4 = new QLabel(Widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        gen_pattern = new QComboBox(Widget);
        gen_pattern->addItem(QString());
        gen_pattern->addItem(QString());
        gen_pattern->addItem(QString());
        gen_pattern->addItem(QString());
        gen_pattern->addItem(QString());
        gen_pattern->setObjectName(QStringLiteral("gen_pattern"));

        verticalLayout->addWidget(gen_pattern);

        generate = new QPushButton(Widget);
        generate->setObjectName(QStringLiteral("generate"));

        verticalLayout->addWidget(generate);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        comboBox = new QComboBox(Widget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout->addWidget(comboBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton_4 = new QPushButton(Widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        time_c = new QLabel(Widget);
        time_c->setObjectName(QStringLiteral("time_c"));

        verticalLayout->addWidget(time_c);

        listWidget = new QListWidget(Widget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setMaximumSize(QSize(100, 16777215));

        verticalLayout->addWidget(listWidget);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Convex Hull", nullptr));
        label_2->setText(QApplication::translate("Widget", "Amount of points:", nullptr));
        comboBox_2->setItemText(0, QApplication::translate("Widget", "1000", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("Widget", "5000", nullptr));
        comboBox_2->setItemText(2, QApplication::translate("Widget", "10000", nullptr));
        comboBox_2->setItemText(3, QApplication::translate("Widget", "25000", nullptr));
        comboBox_2->setItemText(4, QApplication::translate("Widget", "50000", nullptr));
        comboBox_2->setItemText(5, QApplication::translate("Widget", "75000", nullptr));
        comboBox_2->setItemText(6, QApplication::translate("Widget", "100000", nullptr));
        comboBox_2->setItemText(7, QApplication::translate("Widget", "250000", nullptr));
        comboBox_2->setItemText(8, QApplication::translate("Widget", "500000", nullptr));
        comboBox_2->setItemText(9, QApplication::translate("Widget", "750000", nullptr));
        comboBox_2->setItemText(10, QApplication::translate("Widget", "1000000", nullptr));

        label_4->setText(QApplication::translate("Widget", "Pattern:", nullptr));
        gen_pattern->setItemText(0, QApplication::translate("Widget", "Random", nullptr));
        gen_pattern->setItemText(1, QApplication::translate("Widget", "Grid", nullptr));
        gen_pattern->setItemText(2, QApplication::translate("Widget", "Square", nullptr));
        gen_pattern->setItemText(3, QApplication::translate("Widget", "Circle", nullptr));
        gen_pattern->setItemText(4, QApplication::translate("Widget", "Elipse", nullptr));

        generate->setText(QApplication::translate("Widget", "Generate points", nullptr));
        label->setText(QApplication::translate("Widget", "Select method:", nullptr));
        comboBox->setItemText(0, QApplication::translate("Widget", "Jarvis Scan", nullptr));
        comboBox->setItemText(1, QApplication::translate("Widget", "Quick Hull", nullptr));
        comboBox->setItemText(2, QApplication::translate("Widget", "Sweep Line", nullptr));

        pushButton_4->setText(QApplication::translate("Widget", "Test", nullptr));
        pushButton->setText(QApplication::translate("Widget", "Create convex hull", nullptr));
        label_3->setText(QApplication::translate("Widget", "Duration in [s]:", nullptr));
        time_c->setText(QString());
        pushButton_2->setText(QApplication::translate("Widget", "Clear points", nullptr));
        pushButton_3->setText(QApplication::translate("Widget", "Clear convex hull", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
