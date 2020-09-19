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
    QString file_name;
    QString text;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_plainTextEdit_textChanged();

    void on_pushButton_write_clicked();

    void on_pushButton_read_clicked();

    void on_pushButton_open_clicked();

    void on_pushButton_process_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
