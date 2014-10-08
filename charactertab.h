#ifndef CHARACTERTAB_H
#define CHARACTERTAB_H

#include <QDialog>
#include <QTabWidget>
#include <QLabel>
#include <QScrollArea>

namespace Ui {
class charactertab;
}

class charactertab : public QDialog
{
    Q_OBJECT

public:
    explicit charactertab(QWidget *parent = 0);
    charactertab(QTabWidget *parent, QScrollArea *PCO, QScrollArea *NPCO, QLabel *overview, int index);
    ~charactertab();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::charactertab *ui;
    QTabWidget* parentTab;
    QLabel* overview;
    QScrollArea *PCO;
    QScrollArea *NPCO;
    int index;
};

#endif // CHARACTERTAB_H
