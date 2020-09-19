#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QDir>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_process->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_write_clicked()
{
    QFile file(file_name);

    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "title", "msg");
    }

    QTextStream out(&file);
    QString text = ui->plainTextEdit->toPlainText();
    out << text;

    file.flush();
    file.close();
}


void MainWindow::on_pushButton_open_clicked()
{
    file_name = QFileDialog::getOpenFileName(this, "Open a file", QDir::currentPath() + "/../lab9qt");
    QMessageBox::information(this, "Open file", file_name);

    QFile file(file_name);

    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "title", "msg");
    }

    QTextStream in(&file);
    text = in.readAll();
    ui->plainTextEdit->setPlainText(text);

    ui->pushButton_process->show();

    file.close();
}

void MainWindow::on_pushButton_process_clicked()
{
    QStringList cities = text.split(",");

    QRegExp rx("\\d(\\-|\\.|\\ )\\d");
    QStringList city = cities.filter(rx);
    QString list = "";

    for (int i = 0; i < city.length(); i++) {
        list += city[i];
        if (i + 1 != city.length()) list += ",";
    }

    QMessageBox::warning(this, "title", list);
}
