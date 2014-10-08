#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "charactertab.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    charactersNumber = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_charactersTab_tabBarClicked(int index)
{
    if (index==charactersNumber+1)
    {
        charactersNumber++;
        QLabel *overview = new QLabel();

        ui->gridLayout->addWidget(overview);
        overview->setText("Bob Morane");
        ui->charactersTab->insertTab(charactersNumber,new charactertab(ui->charactersTab,ui->PCO,ui->NPCO,overview,index),"Bob Morane");
    }
}

void MainWindow::on_charactersTab_currentChanged(int index)
{

}
