#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "charactertab.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    characterNumber = 0;
    PCOL = new QVBoxLayout();
    PCOL->setMargin(0);
    PCOL->setContentsMargins(0,0,0,0);
    ui->PCOC->setLayout(PCOL);
    NPCOL = new QVBoxLayout();
    NPCOL->setMargin(0);
    NPCOL->setContentsMargins(0,0,0,0);
    ui->NPCOC->setLayout(NPCOL);
    ui->charactersTab->setCurrentIndex(0);
    ui->charactersTab->setTabsClosable(true);
    this->location = "/";

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::decreaseCharacterNumber()
{
    characterNumber--;
}

void MainWindow::setWorldActive()
{
        ui->charactersTab->setCurrentIndex(0);
}

void MainWindow::resizeLayouts()
{
    this->ui->PCOC->setFixedHeight(PCOL->count()*20);
    int count=NPCOL->count();
    this->ui->NPCOC->setFixedHeight(NPCOL->count()*20);
    this->ui->PCOC->setFixedHeight(PCOL->count()*20);
}

void MainWindow::on_charactersTab_tabBarClicked(int index)
{
    if (index==characterNumber+1)
    {
        characterNumber++;
        QLabel *overview = new QLabel();
        PCOL->addWidget(overview,0, Qt::AlignTop);
        overview->setText("Name, description");
        this->resizeLayouts();
        ui->charactersTab->insertTab(characterNumber,new charactertab(ui->charactersTab,PCOL,NPCOL,overview,index,this),"Name");
        ui->charactersTab->setCurrentIndex(characterNumber);
    }
}


void MainWindow::on_charactersTab_tabCloseRequested(int index)
{
    if (index != 0 && index != characterNumber +1)
        delete ui->charactersTab->widget(index);
}

void MainWindow::on_name_textChanged(const QString &arg1)
{
    this->setWindowTitle("Hello, "+arg1+"!");
}
