/********************************************************************************
** Form generated from reading UI file 'sort.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SORT_H
#define UI_SORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_Sort
{
public:
    QListView *listView;
    QListWidget *listWidget;

    void setupUi(QDialog *Sort)
    {
        if (Sort->objectName().isEmpty())
            Sort->setObjectName(QString::fromUtf8("Sort"));
        Sort->resize(735, 445);
        listView = new QListView(Sort);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(40, 40, 256, 192));
        listWidget = new QListWidget(Sort);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(380, 130, 256, 192));

        retranslateUi(Sort);

        QMetaObject::connectSlotsByName(Sort);
    } // setupUi

    void retranslateUi(QDialog *Sort)
    {
        Sort->setWindowTitle(QApplication::translate("Sort", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Sort: public Ui_Sort {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SORT_H
