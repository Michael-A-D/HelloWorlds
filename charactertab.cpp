#include "charactertab.h"
#include "ui_charactertab.h"

charactertab::charactertab(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::charactertab)
{
    ui->setupUi(this);
}

charactertab::charactertab(QTabWidget *parent, QScrollArea *PCO, QScrollArea *NPCO, QLabel *overview, int index) :
    QDialog(parent),
    ui(new Ui::charactertab)
{
    ui->setupUi(this);
    this->parentTab = parent;
    this->PCO = PCO;
    this->NPCO = NPCO;
    this->overview = overview;
    this->index = index;
}

charactertab::~charactertab()
{
    delete ui;
}

void charactertab::on_lineEdit_textChanged(const QString &arg1)
{
    this->parentTab->setTabText(index,arg1);
    this->overview->setText(arg1);
}
