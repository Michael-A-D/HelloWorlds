#include "abilityform.h"
#include "ui_abilityform.h"

abilityform::abilityform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::abilityform)
{
    ui->setupUi(this);
}

abilityform::abilityform(attributeForm* parent,abilityC* abilityData):
    QWidget(parent),
    ui(new Ui::abilityform)
{
    ui->setupUi(this);
    this->parent = parent;
    this->abilityData = abilityData;
}

abilityform::~abilityform()
{
    delete ui;
    parent->setFixedHeight(parent->height()-40);
}


QLabel* abilityform::getTotal(){
    return this->ui->total;
}

void abilityform::on_pushButton_clicked()
{
    this->parent->attributeData->abilityList.removeOne(this->abilityData);
    this->parent->updateScore();
    this->parent->parent->updateScore();
    delete this;    
}
void abilityform::updateTotal()
{
    this->ui->total->setText("+ " + QString::number(this->parent->attributeData->value)+ " = " + QString::number(this->parent->attributeData->value+this->ui->value->text().toInt()));
}

void abilityform::updateScore()
{
    this->ui->score->setText("Score: "+ QString::number(this->abilityData->score));
}

void abilityform::on_value_valueChanged(const QString &arg1)
{
    this->abilityData->updateValue(arg1.toInt());
    this->updateScore();
    this->parent->updateScore();
    this->parent->parent->updateScore();
    this->updateTotal();
}

void abilityform::on_costBox_valueChanged(const QString &arg1)
{
    this->abilityData->cost = arg1.toInt();
    this->abilityData->updateValue(this->abilityData->value);
    this->parent->computeAndUpdateCost();
    this->updateScore();
    this->parent->updateScore();
    this->parent->parent->updateScore();
}
