#ifndef CHARACTERTAB_H
#define CHARACTERTAB_H

#include <QDialog>
#include <QTabWidget>
#include <QLabel>
#include <QScrollArea>
#include <QVBoxLayout>
#include "mainwindow.h"

namespace Ui {
class charactertab;
}

class charactertab : public QDialog
{
    Q_OBJECT

public:
    explicit charactertab(QWidget *parent = 0);
    charactertab(QTabWidget *parent, QVBoxLayout *PCOL, QVBoxLayout *NPCOL, QLabel *overview, int index, MainWindow *main);
    ~charactertab();

private slots:
    void on_name_textChanged(const QString &arg1);

    void on_npc_toggled(bool checked);

    void on_pushButton_clicked();

    void on_descritpion_textChanged(const QString &arg1);

private:
    Ui::charactertab *ui;
    QTabWidget* parentTab;
    QLabel* overview;
    QVBoxLayout *PCOL;
    QVBoxLayout *NPCOL;
    int index;
    QVBoxLayout *attributeL;
    MainWindow *main;
};

#endif // CHARACTERTAB_H
