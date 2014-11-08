#ifndef ABILITYFORM_H
#define ABILITYFORM_H

#include <QWidget>
#include <attributeform.h>
#include <core.h>

namespace Ui {
class abilityform;
}

class abilityform : public QWidget
{
    Q_OBJECT

public:
    explicit abilityform(QWidget *parent = 0);
    abilityform(attributeForm* parent, abilityC* abilityData);
    ~abilityform();
    QLabel* getTotal();
    Ui::abilityform *ui;
    void updateTotal();
    void updateScore();
    void loadFromData();
private slots:
    void on_pushButton_clicked();

    void on_value_valueChanged(const QString &arg1);

    void on_costBox_valueChanged(const QString &arg1);

    void on_lineEdit_textChanged(const QString &arg1);

private:

    attributeForm* parent;
    abilityC* abilityData;
};

#endif // ABILITYFORM_H
