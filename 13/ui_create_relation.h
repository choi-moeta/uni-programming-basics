/********************************************************************************
** Form generated from reading UI file 'create_relation.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATE_RELATION_H
#define UI_CREATE_RELATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Create_relation
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QComboBox *dishes;
    QLabel *label;
    QComboBox *ingredients;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *Create_relation)
    {
        if (Create_relation->objectName().isEmpty())
            Create_relation->setObjectName(QString::fromUtf8("Create_relation"));
        Create_relation->resize(395, 315);
        gridLayout = new QGridLayout(Create_relation);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        dishes = new QComboBox(Create_relation);
        dishes->setObjectName(QString::fromUtf8("dishes"));

        verticalLayout->addWidget(dishes);

        label = new QLabel(Create_relation);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        ingredients = new QComboBox(Create_relation);
        ingredients->setObjectName(QString::fromUtf8("ingredients"));

        verticalLayout->addWidget(ingredients);

        pushButton = new QPushButton(Create_relation);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Create_relation);

        QMetaObject::connectSlotsByName(Create_relation);
    } // setupUi

    void retranslateUi(QDialog *Create_relation)
    {
        Create_relation->setWindowTitle(QApplication::translate("Create_relation", "Dialog", nullptr));
        label->setText(QApplication::translate("Create_relation", "<=>", nullptr));
        pushButton->setText(QApplication::translate("Create_relation", "Create", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Create_relation: public Ui_Create_relation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATE_RELATION_H
