#ifndef CHARACTERTAB_H
#define CHARACTERTAB_H

#include <QDialog>
#include <QTabWidget>
#include <QLabel>
#include <QScrollArea>
#include <QVBoxLayout>
#include <mainwindow.h>
#include <core.h>

namespace Ui {
class charactertab;
}

class charactertab : public QDialog
{
    Q_OBJECT

public:
    explicit charactertab(QWidget *parent = 0);
    charactertab(QTabWidget *parent, QVBoxLayout *PCOL, QVBoxLayout *NPCOL, QPushButton *overview, int index, MainWindow *main, characterC* characterData);
    ~charactertab();    
    void updateScore();
    void resizeLayout();
    characterC* characterData;

private slots:
    void on_name_textChanged(const QString &arg1);

    void on_npc_toggled(bool checked);

    void on_pushButton_clicked();

    void on_descritpion_textChanged(const QString &arg1);

    void on_HP_valueChanged(int arg1);

    void on_HPCost_valueChanged(int arg1);

    void on_DMG_valueChanged(int arg1);

    void on_DMGCost_valueChanged(int arg1);

    void on_setAvatar_clicked();

    void setActive();

private:
    Ui::charactertab *ui;
    QTabWidget* parentTab;
    QPushButton* overview;
    QVBoxLayout *PCOL;
    QVBoxLayout *NPCOL;
    int index;
    QVBoxLayout *attributeL;
    MainWindow *main;
};

#endif // CHARACTERTAB_H
