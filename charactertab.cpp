#include "charactertab.h"
#include "ui_charactertab.h"
#include "attributeform.h"

charactertab::charactertab(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::charactertab)
{
    ui->setupUi(this);
}

charactertab::charactertab(QTabWidget *parent, QVBoxLayout *PCOL, QVBoxLayout *NPCOL, QLabel *overview, int index, MainWindow *main) :
    QDialog(parent),
    ui(new Ui::charactertab)
{
    ui->setupUi(this);
    this->parentTab = parent;
    this->PCOL = PCOL;
    this->NPCOL = NPCOL;
    this->overview = overview;
    this->index = index;   
    this->main = main;
    attributeL = new QVBoxLayout();
    attributeL->setMargin(0);
    attributeL->setContentsMargins(0,0,0,0);
    ui->attribute->setLayout(attributeL);
    this->characterData = new characterC();
}

charactertab::~charactertab()
{
    delete ui;
    delete this->overview;
    main->decreaseCharacterNumber();
}

void charactertab::updateScore(){
    this->ui->score->setText("Score: "+QString::number(this->characterData->score()));
}

void charactertab::on_name_textChanged(const QString &arg1)
{
    this->parentTab->setTabText(index,arg1);
    this->overview->setText(arg1+", "+ui->descritpion->text());
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
}

void charactertab::on_pushButton_clicked()
{
    attributeC* attributeData = new attributeC();
    attributeForm *attribute = new attributeForm(this,attributeData);
    this->characterData->attributeList.insert(this->characterData->attributeList.size(),attributeData);
    attribute->setFixedHeight(100);
    attributeL->addWidget(attribute);
}

void charactertab::on_descritpion_textChanged(const QString &arg1)
{
    this->overview->setText(ui->name->text()+", "+arg1);
}
