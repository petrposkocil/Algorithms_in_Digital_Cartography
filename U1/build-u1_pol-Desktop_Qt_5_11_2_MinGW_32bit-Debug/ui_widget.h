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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <draw.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *importPolygons;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QComboBox *comboBox;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer_5;
    QPushButton *pushButton_3;
    Draw *Canvas;
    QLabel *inandout;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(710, 584);
        Widget->setStyleSheet(QStringLiteral(""));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 135, 561));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        importPolygons = new QPushButton(layoutWidget);
        importPolygons->setObjectName(QStringLiteral("importPolygons"));
        importPolygons->setStyleSheet(QStringLiteral("QPushButton#importPolygons { background-color: magenta }"));

        verticalLayout->addWidget(importPolygons);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(true);

        verticalLayout->addWidget(pushButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        comboBox = new QComboBox(layoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout->addWidget(comboBox);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setStyleSheet(QStringLiteral("QPushButton#pushButton_2 { background-color: rgb(64, 224, 208) }"));

        verticalLayout->addWidget(pushButton_2);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        Canvas = new Draw(Widget);
        Canvas->setObjectName(QStringLiteral("Canvas"));
        Canvas->setGeometry(QRect(160, 10, 541, 561));
        Canvas->setStyleSheet(QStringLiteral("color: rgb(255, 0, 127);"));
        inandout = new QLabel(Canvas);
        inandout->setObjectName(QStringLiteral("inandout"));
        inandout->setGeometry(QRect(0, 0, 81, 31));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Winding and Ray Crossing Algorithms", nullptr));
        importPolygons->setText(QApplication::translate("Widget", "Import Polygons", nullptr));
        pushButton->setText(QApplication::translate("Widget", "Draw point Q", nullptr));
        label->setText(QApplication::translate("Widget", "Select method:", nullptr));
        comboBox->setItemText(0, QApplication::translate("Widget", "Winding Number", nullptr));
        comboBox->setItemText(1, QApplication::translate("Widget", "Ray Crossing", nullptr));

        label_2->setText(QString());
        pushButton_2->setText(QApplication::translate("Widget", "Analyze", nullptr));
        pushButton_3->setText(QApplication::translate("Widget", "Clear", nullptr));
        inandout->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
