#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "charactertab.h"
#include "xml.h"
#include "QFileDialog"
#include "latex.h"

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

void MainWindow::updateNames()
{
    for(int i=0; i < this->characterNumber; i++)
    {
       this->ui->charactersTab->setTabText(i+1,this->world->characterList.at(i)->name);
    }
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
        ui->charactersTab->insertTab(characterNumber,new charactertab(this,PCOL,NPCOL,overview,index,this,characterData),"Name");
        ui->charactersTab->setCurrentIndex(characterNumber);
        this->world->characterList.push_back(characterData);
    }
}


void MainWindow::on_charactersTab_tabCloseRequested(int index)
{
    if (index != 0 && index != characterNumber +1)
    {
        delete ui->charactersTab->widget(index);
        characterC* characterData = this->world->characterList.at(index-1);
        this->world->characterList.removeAt(index-1);
        delete characterData;
    }
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
        delete writer;
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
        delete writer;
    }
    else
    {
        QMessageBox* message = new QMessageBox();
        message->setText(tr("Please select a character tab."));
        message->exec();
        delete message;
    }
}

void MainWindow::on_actionLoad_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Please select character file"),this->locationCharacter,tr("XML (*.xml)"));
    characterLoader* loader = new characterLoader();
    characterC* characterData = new characterC();
    if(loader->load(characterData,fileName))
    {
        characterNumber++;
        QPushButton *overview = new QPushButton();
        overview->setFixedHeight(20);
        PCOL->addWidget(overview,0, Qt::AlignTop);
        overview->setText("Name, description");
        overview->setFlat(true);
        this->resizeLayouts();
        charactertab* tab = new charactertab(this,PCOL,NPCOL,overview,characterNumber,this,characterData);
        ui->charactersTab->insertTab(characterNumber,tab,"Name");
        ui->charactersTab->setCurrentIndex(characterNumber);
        this->world->characterList.push_back(characterData);
        characterData->fileName = fileName;
        tab->loadFromData();
    }
    else
    {
        delete characterData;
        QMessageBox* message = new QMessageBox();
        message->setText(tr("The file could not be opened, or is not a valid character file."));
        message->exec();
        delete message;
    }
    delete loader;
}

void MainWindow::on_actionSave_World_As_triggered()
{
    worldWriter* writer = new worldWriter();
    QString fileName = QFileDialog::getOpenFileName(this,tr("Please select character file"),this->locationCharacter,tr("XML (*.xml)"));
    if (fileName.size() == 0 || fileName.at(fileName.size()-1) == tr("/"))
        fileName = tr("");
    QStringRef* fileNameReg = new QStringRef(&fileName);
    this->locationWorld = fileName.section("/",0,fileNameReg->count("/")-1);
    this->world->fileName = fileName;
    writer->write(this->world,fileName);
    delete writer;
}

void MainWindow::on_actionLoad_World_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Please select world file"),this->locationWorld,tr("XML (*.xml)"));
    QStringRef* fileNameReg = new QStringRef(&fileName);
    this->locationWorld = fileName.section("/",0,fileNameReg->count("/")-1);
    worldLoader* loader = new worldLoader();
    if(loader->load(this->world,fileName))
    {
        this->world->fileName = fileName;
        this->ui->name->setText(this->world->name);
        this->ui->plainTextEdit->setPlainText(this->world->description);
        for (int i = this->characterNumber;i<this->world->characterList.size();i++)
        {
            characterNumber++;
            QPushButton *overview = new QPushButton();
            overview->setFixedHeight(20);
            PCOL->addWidget(overview,0, Qt::AlignTop);
            overview->setText("Name, description");
            overview->setFlat(true);
            this->resizeLayouts();
            charactertab* tab = new charactertab(this,PCOL,NPCOL,overview,i+1,this,this->world->characterList.at(i));
            ui->charactersTab->insertTab(i+1,tab,"Name");
            tab->loadFromData();
        }
        this->characterNumber = this->world->characterList.size();
    }
    else
    {
        QMessageBox* message = new QMessageBox();
        message->setText(tr("The file could not be opened, or is not a valid world file."));
        message->exec();
        delete message;
    }
    delete loader;

}

void MainWindow::on_actionNew_World_triggered()
{
    worldWriter* writer = new worldWriter();
    if (this->world->fileName == "")
    {
        QString fileName = QFileDialog::getOpenFileName(this,tr("Please select world file"),this->locationCharacter,tr("XML (*.xml)"));
        if (fileName.size() == 0 || fileName.at(fileName.size()-1) == tr("/"))
            fileName = tr("");
        QStringRef* fileNameReg = new QStringRef(&fileName);
        this->locationWorld = fileName.section("/",0,fileNameReg->count("/")-1);
        this->world->fileName = fileName;
    }
    writer->write(this->world,this->world->fileName);
    delete writer;
}

void MainWindow::on_actionExport_triggered()
{
    if ((this->ui->charactersTab->currentIndex() !=0) && (this->ui->charactersTab->currentIndex() != this->characterNumber + 1)){
        QString fileName = QFileDialog::getOpenFileName(this,tr("Please select PDF file"),this->locationCharacter,tr("PDF (*.pdf)"));
        latex* writer = new  latex();
        writer->write(this->world->characterList.at(this->ui->charactersTab->currentIndex()-1),fileName); }
    else
    {
        QMessageBox* message = new QMessageBox();
        message->setText(tr("Please select a character tab."));
        message->exec();
        delete message;
    }
}
