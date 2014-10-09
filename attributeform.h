#ifndef ATTRIBUTEFORM_H
#define ATTRIBUTEFORM_H

#include <QWidget>
#include <QVBoxLayout>
#include <core.h>
#include <charactertab.h>

namespace Ui {
class attributeForm;
}

class attributeForm : public QWidget
{
    Q_OBJECT

public:
    explicit attributeForm(QWidget *parent = 0);
    attributeForm(charactertab *parent, attributeC* attributeData);
    ~attributeForm();
    attributeC* attributeData;
    charactertab* parent;
    void updateScore();
    void computeAndUpdateCost();

private slots:
    void on_pushButton_clicked();

    void on_deleteButton_clicked();

    void on_customBox_toggled(bool checked);

    void on_value_valueChanged(const QString &arg1);

    void on_customValue_valueChanged(const QString &arg1);

private:
    Ui::attributeForm *ui;
    QGridLayout *abilityL;
    void updateCost();
};

#endif // ATTRIBUTEFORM_H
