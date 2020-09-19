#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void updateTable();
    void on_pushButton_new_clicked();
    void on_pushButton_delete_clicked();

    void on_pushButton_saveBin_clicked();
    void on_pushButton_loadBin_clicked();

    void on_pushButton_saveHum_clicked();

    void on_pushButton_sort_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
