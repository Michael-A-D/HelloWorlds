#ifndef ABILITYFORM_H
#define ABILITYFORM_H

#include <QWidget>

namespace Ui {
class abilityform;
}

class abilityform : public QWidget
{
    Q_OBJECT

public:
    explicit abilityform(QWidget *parent = 0);
    ~abilityform();

private:
    Ui::abilityform *ui;
};

#endif // ABILITYFORM_H
