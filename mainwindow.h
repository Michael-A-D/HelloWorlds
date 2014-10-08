#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_charactersTab_tabBarClicked(int index);

    void on_charactersTab_currentChanged(int index);

private:
    Ui::MainWindow *ui;
    int charactersNumber;
};

#endif // MAINWINDOW_H
