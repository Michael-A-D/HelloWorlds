#include "charactertab.h"
#include "ui_charactertab.h"
#include "attributeform.h"

charactertab::charactertab(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::charactertab)
{
    ui->setupUi(this);
}

charactertab::charactertab(QTabWidget *parent, QVBoxLayout *PCOL, QVBoxLayout *NPCOL, QLabel *overview, int index) :
    QDialog(parent),
    ui(new Ui::charactertab)
{
    ui->setupUi(this);
    this->parentTab = parent;
    this->PCOL = PCOL;
    this->NPCOL = NPCOL;
    this->overview = overview;
    this->index = index;   
    attributeL = new QVBoxLayout();
    attributeL->setMargin(0);
    attributeL->setContentsMargins(0,0,0,0);
    ui->attribute->setLayout(attributeL);
}

charactertab::~charactertab()
{
    delete ui;
}

void charactertab::on_lineEdit_textChanged(const QString &arg1)
{
    this->parentTab->setTabText(index,arg1);
    this->overview->setText(arg1+", "+ui->lineEdit_2->text());
}

void charactertab::on_checkBox_toggled(bool checked)
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

void charactertab::on_lineEdit_2_textChanged(const QString &arg1)
{
    this->overview->setText(ui->lineEdit->text()+", "+arg1);
}

void charactertab::on_pushButton_clicked()
{
    attributeForm *attribute = new attributeForm();
    //QLabel *attribute = new QLabel(); attribute->setText("toto");
    attribute->setFixedHeight(100);
    attributeL->addWidget(attribute);
}
