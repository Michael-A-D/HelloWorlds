#ifndef ATTRIBUTEFORM_H
#define ATTRIBUTEFORM_H

#include <QWidget>
#include <QVBoxLayout>

namespace Ui {
class attributeForm;
}

class attributeForm : public QWidget
{
    Q_OBJECT

public:
    explicit attributeForm(QWidget *parent = 0);
    ~attributeForm();

private slots:
    void on_pushButton_clicked();

    void on_deleteButton_clicked();

    void on_customBox_toggled(bool checked);

private:
    Ui::attributeForm *ui;
    QGridLayout *abilityL;
};

#endif // ATTRIBUTEFORM_H
