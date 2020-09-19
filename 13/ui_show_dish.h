/********************************************************************************
** Form generated from reading UI file 'show_dish.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOW_DISH_H
#define UI_SHOW_DISH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Show_Dish
{
public:
    QGridLayout *gridLayout;
    QComboBox *comboBox;
    QTableWidget *tableWidget;

    void setupUi(QDialog *Show_Dish)
    {
        if (Show_Dish->objectName().isEmpty())
            Show_Dish->setObjectName(QString::fromUtf8("Show_Dish"));
        Show_Dish->resize(345, 302);
        gridLayout = new QGridLayout(Show_Dish);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        comboBox = new QComboBox(Show_Dish);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 0, 0, 1, 1);

        tableWidget = new QTableWidget(Show_Dish);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->horizontalHeader()->setDefaultSectionSize(150);
        tableWidget->horizontalHeader()->setStretchLastSection(true);

        gridLayout->addWidget(tableWidget, 1, 0, 1, 1);


        retranslateUi(Show_Dish);

        QMetaObject::connectSlotsByName(Show_Dish);
    } // setupUi

    void retranslateUi(QDialog *Show_Dish)
    {
        Show_Dish->setWindowTitle(QApplication::translate("Show_Dish", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Show_Dish", "Dish", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Show_Dish", "Ingredient", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Show_Dish: public Ui_Show_Dish {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOW_DISH_H
