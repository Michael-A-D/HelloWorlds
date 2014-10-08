#ifndef ATTRIBUTEFORM_H
#define ATTRIBUTEFORM_H

#include <QWidget>

namespace Ui {
class attributeForm;
}

class attributeForm : public QWidget
{
    Q_OBJECT

public:
    explicit attributeForm(QWidget *parent = 0);
    ~attributeForm();

private:
    Ui::attributeForm *ui;
};

#endif // ATTRIBUTEFORM_H
