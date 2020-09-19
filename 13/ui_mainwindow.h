/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget_dishes;
    QTableWidget *tableWidget_ingredients;
    QTableWidget *tableWidget_di;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_add_dish;
    QPushButton *pushButton_add_ingredient;
    QPushButton *pushButton_create_relation;
    QLabel *label_4;
    QPushButton *pushButton_delete_dish;
    QPushButton *pushButton_delete_ingredient;
    QPushButton *pushButton_delete_relation;
    QLabel *label;
    QPushButton *pushButton_load;
    QPushButton *pushButton_save;
    QLabel *label_2;
    QPushButton *pushButton_sort_dishes;
    QPushButton *pushButton_sort_ingredients;
    QLabel *label_3;
    QPushButton *pushButton_show_dish;
    QPushButton *pushButton_show_ingredient;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1221, 568);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"	background: #111;\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tableWidget_dishes = new QTableWidget(centralWidget);
        if (tableWidget_dishes->columnCount() < 3)
            tableWidget_dishes->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_dishes->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_dishes->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_dishes->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget_dishes->setObjectName(QString::fromUtf8("tableWidget_dishes"));
        tableWidget_dishes->setMinimumSize(QSize(400, 0));
        tableWidget_dishes->horizontalHeader()->setStretchLastSection(true);

        horizontalLayout->addWidget(tableWidget_dishes);

        tableWidget_ingredients = new QTableWidget(centralWidget);
        if (tableWidget_ingredients->columnCount() < 3)
            tableWidget_ingredients->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_ingredients->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_ingredients->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_ingredients->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        tableWidget_ingredients->setObjectName(QString::fromUtf8("tableWidget_ingredients"));
        tableWidget_ingredients->setMinimumSize(QSize(400, 0));
        tableWidget_ingredients->horizontalHeader()->setStretchLastSection(true);

        horizontalLayout->addWidget(tableWidget_ingredients);

        tableWidget_di = new QTableWidget(centralWidget);
        if (tableWidget_di->columnCount() < 2)
            tableWidget_di->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_di->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_di->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        tableWidget_di->setObjectName(QString::fromUtf8("tableWidget_di"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget_di->sizePolicy().hasHeightForWidth());
        tableWidget_di->setSizePolicy(sizePolicy);
        tableWidget_di->setMinimumSize(QSize(275, 0));
        tableWidget_di->setMaximumSize(QSize(275, 16777215));
        tableWidget_di->horizontalHeader()->setStretchLastSection(true);

        horizontalLayout->addWidget(tableWidget_di);


        horizontalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_add_dish = new QPushButton(centralWidget);
        pushButton_add_dish->setObjectName(QString::fromUtf8("pushButton_add_dish"));

        verticalLayout->addWidget(pushButton_add_dish);

        pushButton_add_ingredient = new QPushButton(centralWidget);
        pushButton_add_ingredient->setObjectName(QString::fromUtf8("pushButton_add_ingredient"));

        verticalLayout->addWidget(pushButton_add_ingredient);

        pushButton_create_relation = new QPushButton(centralWidget);
        pushButton_create_relation->setObjectName(QString::fromUtf8("pushButton_create_relation"));

        verticalLayout->addWidget(pushButton_create_relation);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        pushButton_delete_dish = new QPushButton(centralWidget);
        pushButton_delete_dish->setObjectName(QString::fromUtf8("pushButton_delete_dish"));

        verticalLayout->addWidget(pushButton_delete_dish);

        pushButton_delete_ingredient = new QPushButton(centralWidget);
        pushButton_delete_ingredient->setObjectName(QString::fromUtf8("pushButton_delete_ingredient"));

        verticalLayout->addWidget(pushButton_delete_ingredient);

        pushButton_delete_relation = new QPushButton(centralWidget);
        pushButton_delete_relation->setObjectName(QString::fromUtf8("pushButton_delete_relation"));

        verticalLayout->addWidget(pushButton_delete_relation);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        pushButton_load = new QPushButton(centralWidget);
        pushButton_load->setObjectName(QString::fromUtf8("pushButton_load"));

        verticalLayout->addWidget(pushButton_load);

        pushButton_save = new QPushButton(centralWidget);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));

        verticalLayout->addWidget(pushButton_save);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        pushButton_sort_dishes = new QPushButton(centralWidget);
        pushButton_sort_dishes->setObjectName(QString::fromUtf8("pushButton_sort_dishes"));

        verticalLayout->addWidget(pushButton_sort_dishes);

        pushButton_sort_ingredients = new QPushButton(centralWidget);
        pushButton_sort_ingredients->setObjectName(QString::fromUtf8("pushButton_sort_ingredients"));

        verticalLayout->addWidget(pushButton_sort_ingredients);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        pushButton_show_dish = new QPushButton(centralWidget);
        pushButton_show_dish->setObjectName(QString::fromUtf8("pushButton_show_dish"));

        verticalLayout->addWidget(pushButton_show_dish);

        pushButton_show_ingredient = new QPushButton(centralWidget);
        pushButton_show_ingredient->setObjectName(QString::fromUtf8("pushButton_show_ingredient"));

        verticalLayout->addWidget(pushButton_show_ingredient);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1221, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_dishes->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_dishes->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_dishes->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Cost", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_ingredients->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_ingredients->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Weight", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_ingredients->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Expire", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_di->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Dish", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_di->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Ingredient", nullptr));
        pushButton_add_dish->setText(QApplication::translate("MainWindow", "Add Dish", nullptr));
        pushButton_add_ingredient->setText(QApplication::translate("MainWindow", "Add Ingridient", nullptr));
        pushButton_create_relation->setText(QApplication::translate("MainWindow", "Create Relation", nullptr));
        label_4->setText(QString());
        pushButton_delete_dish->setText(QApplication::translate("MainWindow", "Delete Dish", nullptr));
        pushButton_delete_ingredient->setText(QApplication::translate("MainWindow", "Delete Ing-t", nullptr));
        pushButton_delete_relation->setText(QApplication::translate("MainWindow", "Delete Relation", nullptr));
        label->setText(QString());
        pushButton_load->setText(QApplication::translate("MainWindow", "Load", nullptr));
        pushButton_save->setText(QApplication::translate("MainWindow", "Save", nullptr));
        label_2->setText(QString());
        pushButton_sort_dishes->setText(QApplication::translate("MainWindow", "Sort Dishes", nullptr));
        pushButton_sort_ingredients->setText(QApplication::translate("MainWindow", "Sort Ing-s", nullptr));
        label_3->setText(QString());
        pushButton_show_dish->setText(QApplication::translate("MainWindow", "Show Dishes", nullptr));
        pushButton_show_ingredient->setText(QApplication::translate("MainWindow", "Show Ing-s", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
