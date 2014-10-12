#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QPushButton>
#include <core.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void decreaseCharacterNumber();
    void setWorldActive();
    void resizeLayouts();
    void setActive(int index);
    worldC* world;
    QString location;
    QString locationCharacter;
    QString locationWorld;
    void updateNames();

private slots:
    void on_charactersTab_tabBarClicked(int index);

    void on_charactersTab_tabCloseRequested(int index);

    void on_name_textChanged(const QString &arg1);

    void on_actionAbout_triggered();

    void on_actionSave_as_triggered();

    void on_actionSave_triggered();

    void on_actionLoad_triggered();

    void on_actionSave_World_As_triggered();

    void on_actionLoad_World_triggered();

    void on_actionNew_World_triggered();

private:
    Ui::MainWindow *ui;
    int characterNumber;
    QVBoxLayout *PCOL;
    QVBoxLayout *NPCOL;
};

#endif // MAINWINDOW_H
