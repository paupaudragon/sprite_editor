#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
using std::cout;
using std::endl;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::test() {
    int x = 0;
    x++;
    x++;

    std::string y = "";

    cout << x << y << endl;
    return;
}
