#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QPushButton>

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
    QString location;

private slots:
    void on_charactersTab_tabBarClicked(int index);

    void on_charactersTab_tabCloseRequested(int index);

    void on_name_textChanged(const QString &arg1);

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
    int characterNumber;
    QVBoxLayout *PCOL;
    QVBoxLayout *NPCOL;
};

#endif // MAINWINDOW_H
