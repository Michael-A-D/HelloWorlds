#include "attributeform.h"
#include "ui_attributeform.h"

attributeForm::attributeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::attributeForm)
{
    ui->setupUi(this);
}

attributeForm::~attributeForm()
{
    delete ui;
}
