#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "charactertab.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    charactersNumber = 0;
    PCOL = new QVBoxLayout(ui->PCOC);
    NPCOL = new QVBoxLayout(ui->NPCOC);
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
        PCOL->addWidget(overview);
        overview->setText("Bob Morane");
        ui->charactersTab->insertTab(charactersNumber,new charactertab(ui->charactersTab,PCOL,NPCOL,overview,index),"Bob Morane");
        ui->charactersTab->setCurrentIndex(charactersNumber);
    }
}
