/********************************************************************************
** Form generated from reading UI file 'show.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOW_H
#define UI_SHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListView>

QT_BEGIN_NAMESPACE

class Ui_show
{
public:
    QListView *listView;

    void setupUi(QDialog *show)
    {
        if (show->objectName().isEmpty())
            show->setObjectName(QString::fromUtf8("show"));
        show->resize(427, 423);
        listView = new QListView(show);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(30, 30, 256, 192));

        retranslateUi(show);

        QMetaObject::connectSlotsByName(show);
    } // setupUi

    void retranslateUi(QDialog *show)
    {
        show->setWindowTitle(QApplication::translate("show", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class show: public Ui_show {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOW_H
