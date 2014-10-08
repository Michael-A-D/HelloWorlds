#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>

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

private slots:
    void on_charactersTab_tabBarClicked(int index);

    void on_charactersTab_tabCloseRequested(int index);

    void on_name_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    int characterNumber;
    QVBoxLayout *PCOL;
    QVBoxLayout *NPCOL;
};

#endif // MAINWINDOW_H
