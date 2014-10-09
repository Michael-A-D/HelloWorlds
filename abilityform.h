#ifndef ABILITYFORM_H
#define ABILITYFORM_H

#include <QWidget>
#include <attributeform.h>

namespace Ui {
class abilityform;
}

class abilityform : public QWidget
{
    Q_OBJECT

public:
    explicit abilityform(QWidget *parent = 0);
    abilityform(attributeForm* parent);
    ~abilityform();

private slots:
    void on_pushButton_clicked();

private:
    Ui::abilityform *ui;
    attributeForm* parent;
};

#endif // ABILITYFORM_H
