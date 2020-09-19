#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void updateTableSql(QSqlQuery);

    void updateTable();

    void updateTableSort(QString);

    void on_pushButton_new_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_load_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_sort_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
