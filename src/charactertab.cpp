#include "charactertab.h"
#include "ui_charactertab.h"
#include "attributeform.h"
#include "QFileDialog"

charactertab::charactertab(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::charactertab)
{
    ui->setupUi(this);
}

charactertab::charactertab(MainWindow *parent, QVBoxLayout *PCOL, QVBoxLayout *NPCOL, QPushButton *overview, int index, MainWindow *main, characterC* characterData) :
    QDialog(parent),
    ui(new Ui::charactertab)
{
    ui->setupUi(this);
    this->parent = parent;
    this->PCOL = PCOL;
    this->NPCOL = NPCOL;
    this->overview = overview;
    connect(overview,&QPushButton::clicked,this,&charactertab::setActive);
    this->index = index;   
    this->main = main;
    attributeL = new QVBoxLayout();
    attributeL->setMargin(0);
    attributeL->setContentsMargins(0,0,0,0);
    ui->attribute->setLayout(attributeL);
    this->characterData = characterData;
}

void charactertab::setActive()
{
    this->main->setActive(this->index);
}

void charactertab::resizeLayout()
{
    int size = 0;
    for(int i = 0; i<this->characterData->attributeList.length(); i++)
    {
        for(int j = 0; j<this->characterData->attributeList.at(i)->abilityList.length(); j++)
        {
            size += 40;
        }
        size += 110;
    }
    this->ui->attribute->setFixedHeight(size);
}

charactertab::~charactertab()
{
    delete ui;
    delete this->overview;
    main->decreaseCharacterNumber();
    main->resizeLayouts();
}

void charactertab::updateScore()
{
    this->ui->score->setText("Score: "+QString::number(this->characterData->score()));
    this->overview->setText(ui->name->text()+", "+ui->descritpion->text() + " ("+ QString::number(this->characterData->score())+")");
}

void charactertab::on_name_textChanged(const QString &arg1)
{
    this->overview->setText(arg1+", "+ui->descritpion->text());
    this->characterData->name = arg1;
    this->parent->updateNames();
}

void charactertab::loadFromData(){
    this->ui->name->setText(this->characterData->name);
    this->ui->descritpion->setText(this->characterData->description);
    this->ui->HP->setValue(this->characterData->hp);
    this->ui->HPCost->setValue(this->characterData->hpCost);
    this->ui->DMG->setValue(this->characterData->dmg);
    this->ui->DMGCost->setValue(this->characterData->dmgCost);
    this->ui->npc->setChecked(this->characterData->NPC);
    this->ui->avatar->setText(this->characterData->avatar.section("/",-1));
    foreach(attributeC* attribute, this->characterData->attributeList){
        attributeForm* form = new attributeForm(this,attribute);
        form->setFixedHeight(100);
        form->loadFromData();
        attributeL->addWidget(form);
    }
    this->resizeLayout();
    this->updateScore();
}

void charactertab::on_npc_toggled(bool checked)
{
    if (checked)
    {
        this->NPCOL->addWidget(this->overview,0, Qt::AlignTop);
    }
    else
    {
        this->PCOL->addWidget(this->overview,0, Qt::AlignTop);
    }
    this->main->resizeLayouts();
    this->characterData->NPC = checked;
}

void charactertab::on_pushButton_clicked()
{
    attributeC* attributeData = new attributeC();
    attributeForm *attribute = new attributeForm(this,attributeData);
    this->characterData->attributeList.insert(this->characterData->attributeList.size(),attributeData);
    attribute->setFixedHeight(100);
    attributeL->addWidget(attribute);
    this->resizeLayout();
}

void charactertab::on_descritpion_textChanged(const QString &arg1)
{
    this->overview->setText(ui->name->text()+", "+arg1);
    this->characterData->description = arg1;
}

void charactertab::on_HP_valueChanged(int arg1)
{
    this->characterData->hp = arg1;
    this->updateScore();
}

void charactertab::on_HPCost_valueChanged(int arg1)
{
    this->characterData->hpCost = arg1;
    this->updateScore();
}

void charactertab::on_DMG_valueChanged(int arg1)
{
    this->characterData->dmg = arg1;
    this->updateScore();
}

void charactertab::on_DMGCost_valueChanged(int arg1)
{
    this->characterData->dmgCost = arg1;
    this->updateScore();
}

void charactertab::on_setAvatar_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Please select avatar"),this->main->location,tr("Files (*.*)"));
    this->ui->avatar->setText(fileName.section("/",-1));
    QStringRef* fileNameReg = new QStringRef(&fileName);
    this->main->location = fileName.section("/",0,fileNameReg->count("/")-1);
    this->characterData->avatar = fileName;
}
