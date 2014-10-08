#include "abilityform.h"
#include "ui_abilityform.h"

abilityform::abilityform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::abilityform)
{
    ui->setupUi(this);
}

abilityform::~abilityform()
{
    delete ui;
}
