#include "attributeform.h"
#include "ui_attributeform.h"
#include "abilityform.h"

attributeForm::attributeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::attributeForm)
{
    ui->setupUi(this);
    abilityL = new QGridLayout();
    abilityL->setMargin(0);
    abilityL->setContentsMargins(0,0,0,0);
    ui->ability->setLayout(abilityL);
}

attributeForm::~attributeForm()
{
    delete ui;
}

void attributeForm::on_pushButton_clicked()
{
    abilityform *ability = new abilityform();
    ability->setFixedHeight(35);
    abilityL->addWidget(ability);
    this->setFixedHeight(this->height()+35);
}
