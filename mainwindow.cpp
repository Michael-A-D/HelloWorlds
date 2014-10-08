#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "charactertab.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    charactersNumber = 0;
    PCOL = new QVBoxLayout();
    PCOL->setMargin(0);
    PCOL->setContentsMargins(0,0,0,0);
    ui->PCOC->setLayout(PCOL);
    NPCOL = new QVBoxLayout(ui->NPCOC);
    ui->charactersTab->setCurrentIndex(0);

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
        PCOL->addWidget(overview,0, Qt::AlignTop);
        overview->setText("Unnamed character, unknown");
        ui->charactersTab->insertTab(charactersNumber,new charactertab(ui->charactersTab,PCOL,NPCOL,overview,index),"Unnamed character");
        ui->charactersTab->setCurrentIndex(charactersNumber);
    }
}
