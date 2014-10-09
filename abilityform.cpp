#include "abilityform.h"
#include "ui_abilityform.h"

abilityform::abilityform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::abilityform)
{
    ui->setupUi(this);
}

abilityform::abilityform(attributeForm* parent):
    QWidget(parent),
    ui(new Ui::abilityform)
{
    ui->setupUi(this);
    this->parent = parent;
}

abilityform::~abilityform()
{
    delete ui;
    parent->setFixedHeight(parent->height()-35);
}



void abilityform::on_pushButton_clicked()
{
    delete this;
}
