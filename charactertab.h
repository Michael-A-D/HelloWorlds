#ifndef CHARACTERTAB_H
#define CHARACTERTAB_H

#include <QDialog>
#include <QTabWidget>
#include <QLabel>
#include <QScrollArea>
#include <QVBoxLayout>

namespace Ui {
class charactertab;
}

class charactertab : public QDialog
{
    Q_OBJECT

public:
    explicit charactertab(QWidget *parent = 0);
    charactertab(QTabWidget *parent, QVBoxLayout *PCOL, QVBoxLayout *NPCOL, QLabel *overview, int index);
    ~charactertab();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

    void on_checkBox_toggled(bool checked);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::charactertab *ui;
    QTabWidget* parentTab;
    QLabel* overview;
    QVBoxLayout *PCOL;
    QVBoxLayout *NPCOL;
    int index;
    QVBoxLayout *attributeL;
};

#endif // CHARACTERTAB_H
