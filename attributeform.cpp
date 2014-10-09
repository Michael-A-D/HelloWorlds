#include "attributeform.h"
#include "ui_attributeform.h"
#include "abilityform.h"
#include "core.h"

attributeForm::attributeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::attributeForm)
{
    ui->setupUi(this);
    abilityL = new QGridLayout();
    abilityL->setMargin(0);
    abilityL->setContentsMargins(0,0,0,0);
    ui->ability->setLayout(abilityL);
    this->ui->deleteButton->setFixedWidth(27);
    this->ui->customValue->setEnabled(false);
}

attributeForm::attributeForm(charactertab* parent, attributeC* attributeData) :
    QWidget(parent),
    ui(new Ui::attributeForm)
{
    ui->setupUi(this);
    abilityL = new QGridLayout();
    abilityL->setMargin(0);
    abilityL->setContentsMargins(0,0,0,0);
    ui->ability->setLayout(abilityL);
    this->ui->deleteButton->setFixedWidth(27);
    this->ui->customValue->setEnabled(false);
    this->parent = parent;
    this->attributeData = attributeData;
}

attributeForm::~attributeForm()
{
    delete ui;
}

void attributeForm::on_pushButton_clicked()
{
    abilityC* abilityData = new abilityC();
    this->attributeData->abilityList.push_back(abilityData);
    abilityform* ability = new abilityform(this,abilityData);
    abilityData->total = ability->getTotal();
    ability->setFixedHeight(35);
    abilityL->addWidget(ability);
    this->setFixedHeight(this->height()+40);
    if (this->ui->customBox->checkState() == Qt::Unchecked)
    {
        this->attributeData->cost = this->attributeData->calculatedCost();
    };
    this->updateCost();
    this->updateScore();
    this->parent->updateScore();
    this->parent->resizeLayout();
}
void attributeForm::updateScore(){
    this->ui->score->setText("Score: "+QString::number(this->attributeData->score()));
}
void attributeForm::computeAndUpdateCost(){
    if (this->ui->customBox->checkState() == Qt::Unchecked)
    {
        this->attributeData->cost = this->attributeData->calculatedCost();
    }
    else
    {
        this->attributeData->cost = this->ui->customValue->text().toInt();
    };
    this->updateCost();
    this->parent->updateScore();
}

void attributeForm::on_deleteButton_clicked()
{
    this->parent->characterData->attributeList.removeOne(this->attributeData);
    this->parent->updateScore();
    this->parent->resizeLayout();
    delete this;
}

void attributeForm::updateCost(){
    this->ui->calculateCost->setText("Calculated cost: " + QString::number(this->attributeData->calculatedCost()));
}

void attributeForm::on_customBox_toggled(bool checked)
{
    this->ui->customValue->setEnabled(checked);
    this->computeAndUpdateCost();
    this->attributeData->isCustom = checked;
}

void attributeForm::on_value_valueChanged(const QString &arg1)
{
    this->attributeData->value = arg1.toInt();
    this->parent->updateScore();
    this->updateScore();
    for(int i = 0; i < this->abilityL->count(); i++)
        this->attributeData->abilityList.at(i)->total->setText(
                "+ " + QString::number(this->attributeData->value)+ " = " + QString::number(this->attributeData->value+this->attributeData->abilityList.at(i)->value));
}

void attributeForm::on_customValue_valueChanged(const QString &arg1)
{
    this->attributeData->cost = arg1.toInt();
    this->updateCost();
    this->parent->updateScore();
}
