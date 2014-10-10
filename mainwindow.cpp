#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "charactertab.h"
#include "xml.h"
#include "QFileDialog"

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
    this->world = new worldC();
    this->location = "/";
    this->locationCharacter = "/";
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
    this->ui->PCOC->setFixedHeight(PCOL->count()*25);
    this->ui->NPCOC->setFixedHeight(NPCOL->count()*25);
    this->ui->PCOC->setFixedHeight(PCOL->count()*25);
}
void MainWindow::setActive(int index)
{
    this->ui->charactersTab->setCurrentIndex(index);
}

void MainWindow::on_charactersTab_tabBarClicked(int index)
{
    if (index==characterNumber+1)
    {
        characterNumber++;
        QPushButton *overview = new QPushButton();
        overview->setFixedHeight(20);
        PCOL->addWidget(overview,0, Qt::AlignTop);
        overview->setText("Name, description");
        overview->setFlat(true);
        this->resizeLayouts();
        characterC* characterData = new characterC();
        ui->charactersTab->insertTab(characterNumber,new charactertab(ui->charactersTab,PCOL,NPCOL,overview,index,this,characterData),"Name");
        ui->charactersTab->setCurrentIndex(characterNumber);
        this->world->characterList.push_back(characterData);
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

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox* message = new QMessageBox();
    message->setText(tr("This is Hello, WorldS! alpha 1, released on 10/9/14.\n\n This software uses the GNU Licence: it is free to use and share.\n\n If you find a bug, please report on GitHub:\n https://github.com/Michael-A-D/HelloWorlds/issues"));
    message->exec();
    delete message;
}

void MainWindow::on_actionSave_as_triggered()
{
    if ((this->ui->charactersTab->currentIndex() !=0) && (this->ui->charactersTab->currentIndex() != this->characterNumber + 1)){
        characterWriter* writer = new characterWriter();
        QString fileName = QFileDialog::getOpenFileName(this,tr("Please select character file"),this->locationCharacter,tr("XML (*.xml)"));
        if (fileName.size() == 0 || fileName.at(fileName.size()-1) == tr("/"))
            fileName = tr("");
        QStringRef* fileNameReg = new QStringRef(&fileName);
        this->locationCharacter = fileName.section("/",0,fileNameReg->count("/")-1);
        this->world->characterList.at(this->ui->charactersTab->currentIndex()-1)->fileName = fileName;
        writer->write(this->world->characterList.at(this->ui->charactersTab->currentIndex()-1),this->world->characterList.at(this->ui->charactersTab->currentIndex()-1)->fileName);
    }
    else
    {
        QMessageBox* message = new QMessageBox();
        message->setText(tr("Please select a character tab."));
        message->exec();
        delete message;
    }
}

void MainWindow::on_actionSave_triggered()
{
    if ((this->ui->charactersTab->currentIndex() !=0) && (this->ui->charactersTab->currentIndex() != this->characterNumber + 1)){
        characterWriter* writer = new characterWriter();
        if (this->world->characterList.at(this->ui->charactersTab->currentIndex()-1)->fileName == "")
        {
            QString fileName = QFileDialog::getOpenFileName(this,tr("Please select character file"),this->locationCharacter,tr("XML (*.xml)"));
            if (fileName.size() == 0 || fileName.at(fileName.size()-1) == tr("/"))
                fileName = tr("");
            QStringRef* fileNameReg = new QStringRef(&fileName);
            this->locationCharacter = fileName.section("/",0,fileNameReg->count("/")-1);
            this->world->characterList.at(this->ui->charactersTab->currentIndex()-1)->fileName = fileName;
        }
        writer->write(this->world->characterList.at(this->ui->charactersTab->currentIndex()-1),this->world->characterList.at(this->ui->charactersTab->currentIndex()-1)->fileName);
    }
    else
    {
        QMessageBox* message = new QMessageBox();
        message->setText(tr("Please select a character tab."));
        message->exec();
        delete message;
    }
}
