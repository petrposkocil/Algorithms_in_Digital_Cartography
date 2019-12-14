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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <draw.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout;
    Draw *Canvas;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QComboBox *comboBox;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1375, 916);
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
        radioButton = new QRadioButton(Widget);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout->addWidget(radioButton);

        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        pushButton_5 = new QPushButton(Widget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        verticalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(Widget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        verticalLayout->addWidget(pushButton_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        comboBox = new QComboBox(Widget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout->addWidget(comboBox);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        pushButton_2->setFont(font);

        verticalLayout->addWidget(pushButton_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(Widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Boolean Operations 1.0", nullptr));
        radioButton->setText(QApplication::translate("Widget", "Draw Active", nullptr));
        pushButton->setText(QApplication::translate("Widget", "Polygon A/B", nullptr));
        pushButton_5->setText(QApplication::translate("Widget", "Import Polygons", nullptr));
        pushButton_6->setText(QApplication::translate("Widget", "Select A/B", nullptr));
        label->setText(QApplication::translate("Widget", "Boolean Operations:", nullptr));
        comboBox->setItemText(0, QApplication::translate("Widget", "Union", nullptr));
        comboBox->setItemText(1, QApplication::translate("Widget", "Intersect", nullptr));
        comboBox->setItemText(2, QApplication::translate("Widget", "Difference AB", nullptr));
        comboBox->setItemText(3, QApplication::translate("Widget", "Difference BA", nullptr));

        pushButton_2->setText(QApplication::translate("Widget", "Create Overlay", nullptr));
        pushButton_3->setText(QApplication::translate("Widget", "Clear Results", nullptr));
        pushButton_4->setText(QApplication::translate("Widget", "Clear All", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
