#include "mainwindow.h"
#include "mainwindow.h"

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

void MainWindow:: testFunction1(){
    int i = 1;
    int j = 1;

void MainWindow::testMerge(){
    int x = 0;
    x++;

    int j =0;
    j++

    j = x+2;

}