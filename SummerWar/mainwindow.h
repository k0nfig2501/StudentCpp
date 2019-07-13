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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString str = "";

protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void inputSymbol();
    void inputDot();
    void erase();
    void back();
    void calculate();
    void getSqrt();
    void getSqr();
    void getFact();
    void getLn();
    void getAbs();
    void getSin();
    void getCos();
    void getTg();
    void getExp();
    void getPi();
};

#endif
