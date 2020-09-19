/********************************************************************************
** Form generated from reading UI file 'add_dish.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_DISH_H
#define UI_ADD_DISH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Add_dish
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *Name;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *Type;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDoubleSpinBox *Cost;
    QPushButton *pushButton;

    void setupUi(QDialog *Add_dish)
    {
        if (Add_dish->objectName().isEmpty())
            Add_dish->setObjectName(QString::fromUtf8("Add_dish"));
        Add_dish->resize(400, 293);
        gridLayout = new QGridLayout(Add_dish);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Add_dish);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        Name = new QLineEdit(Add_dish);
        Name->setObjectName(QString::fromUtf8("Name"));

        horizontalLayout->addWidget(Name);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(Add_dish);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        Type = new QLineEdit(Add_dish);
        Type->setObjectName(QString::fromUtf8("Type"));

        horizontalLayout_2->addWidget(Type);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(Add_dish);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        Cost = new QDoubleSpinBox(Add_dish);
        Cost->setObjectName(QString::fromUtf8("Cost"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Cost->sizePolicy().hasHeightForWidth());
        Cost->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(Cost);


        verticalLayout->addLayout(horizontalLayout_3);

        pushButton = new QPushButton(Add_dish);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Add_dish);

        QMetaObject::connectSlotsByName(Add_dish);
    } // setupUi

    void retranslateUi(QDialog *Add_dish)
    {
        Add_dish->setWindowTitle(QApplication::translate("Add_dish", "Dialog", nullptr));
        label->setText(QApplication::translate("Add_dish", "Name", nullptr));
        label_2->setText(QApplication::translate("Add_dish", "Type", nullptr));
        label_3->setText(QApplication::translate("Add_dish", "Cost", nullptr));
        pushButton->setText(QApplication::translate("Add_dish", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Add_dish: public Ui_Add_dish {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_DISH_H
