/********************************************************************************
** Form generated from reading UI file 'add_ingredient.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_INGREDIENT_H
#define UI_ADD_INGREDIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Add_ingredient
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *Name;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *Weight;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QDateEdit *Date;
    QPushButton *pushButton;

    void setupUi(QDialog *Add_ingredient)
    {
        if (Add_ingredient->objectName().isEmpty())
            Add_ingredient->setObjectName(QString::fromUtf8("Add_ingredient"));
        Add_ingredient->resize(400, 300);
        gridLayout = new QGridLayout(Add_ingredient);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(Add_ingredient);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        Name = new QLineEdit(Add_ingredient);
        Name->setObjectName(QString::fromUtf8("Name"));

        horizontalLayout_3->addWidget(Name);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(Add_ingredient);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        Weight = new QDoubleSpinBox(Add_ingredient);
        Weight->setObjectName(QString::fromUtf8("Weight"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Weight->sizePolicy().hasHeightForWidth());
        Weight->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(Weight);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(Add_ingredient);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        Date = new QDateEdit(Add_ingredient);
        Date->setObjectName(QString::fromUtf8("Date"));
        sizePolicy.setHeightForWidth(Date->sizePolicy().hasHeightForWidth());
        Date->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(Date);


        verticalLayout->addLayout(horizontalLayout);

        pushButton = new QPushButton(Add_ingredient);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Add_ingredient);

        QMetaObject::connectSlotsByName(Add_ingredient);
    } // setupUi

    void retranslateUi(QDialog *Add_ingredient)
    {
        Add_ingredient->setWindowTitle(QApplication::translate("Add_ingredient", "Dialog", nullptr));
        label->setText(QApplication::translate("Add_ingredient", "Name", nullptr));
        label_2->setText(QApplication::translate("Add_ingredient", "Weight", nullptr));
        label_3->setText(QApplication::translate("Add_ingredient", "Cost", nullptr));
        pushButton->setText(QApplication::translate("Add_ingredient", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Add_ingredient: public Ui_Add_ingredient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_INGREDIENT_H
