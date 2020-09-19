/********************************************************************************
** Form generated from reading UI file 'show_ingredient.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOW_INGREDIENT_H
#define UI_SHOW_INGREDIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Show_Ingredient
{
public:
    QGridLayout *gridLayout;
    QComboBox *comboBox;
    QTableWidget *tableWidget;

    void setupUi(QDialog *Show_Ingredient)
    {
        if (Show_Ingredient->objectName().isEmpty())
            Show_Ingredient->setObjectName(QString::fromUtf8("Show_Ingredient"));
        Show_Ingredient->resize(400, 300);
        gridLayout = new QGridLayout(Show_Ingredient);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        comboBox = new QComboBox(Show_Ingredient);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 0, 0, 1, 1);

        tableWidget = new QTableWidget(Show_Ingredient);
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


        retranslateUi(Show_Ingredient);

        QMetaObject::connectSlotsByName(Show_Ingredient);
    } // setupUi

    void retranslateUi(QDialog *Show_Ingredient)
    {
        Show_Ingredient->setWindowTitle(QApplication::translate("Show_Ingredient", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Show_Ingredient", "Ingredient", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Show_Ingredient", "Dish", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Show_Ingredient: public Ui_Show_Ingredient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOW_INGREDIENT_H
