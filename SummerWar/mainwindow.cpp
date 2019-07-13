#include "calculator.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QString>
#include <cmath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setText(str);
    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(inputSymbol()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(inputSymbol()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(inputSymbol()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(inputSymbol()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(inputSymbol()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(inputSymbol()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(inputSymbol()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(inputSymbol()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(inputSymbol()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(inputSymbol()));

    connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(inputDot()));
    connect(ui->pushButton_multiply, SIGNAL(clicked()), this, SLOT(inputSymbol()));
    connect(ui->pushButton_divide, SIGNAL(clicked()), this, SLOT(inputSymbol()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(inputSymbol()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(inputSymbol()));
    connect(ui->pushButton_leftBracket, SIGNAL(clicked()), this, SLOT(inputSymbol()));
    connect(ui->pushButton_rightBracket, SIGNAL(clicked()), this, SLOT(inputSymbol()));
    connect(ui->pushButton_C, SIGNAL(clicked()), this, SLOT(erase()));
    connect(ui->pushButton_backspace, SIGNAL(clicked()), this, SLOT(back()));
    connect(ui->pushButton_equal, SIGNAL(clicked()), this, SLOT(calculate()));

    connect(ui->pushButton_abs, SIGNAL(clicked()), this, SLOT(getAbs()));
    connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(getLn()));
    connect(ui->pushButton_sqr, SIGNAL(clicked()), this, SLOT(getSqr()));
    connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(getSqrt()));
    connect(ui->pushButton_fact, SIGNAL(clicked()), this, SLOT(getFact()));
    connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(getSin()));
    connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(getCos()));
    connect(ui->pushButton_tg, SIGNAL(clicked()), this, SLOT(getTg()));
    connect(ui->pushButton_pi, SIGNAL(clicked()), this, SLOT(getPi()));
    connect(ui->pushButton_exp, SIGNAL(clicked()), this, SLOT(getExp()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();
    switch (key) {
    case Qt::Key_0:
        str += Qt::Key_0;
        ui->lineEdit->setText(str);
        break;
    case Qt::Key_1:
        str += Qt::Key_1;
        ui->lineEdit->setText(str);
        break;
    case Qt::Key_2:
        str += Qt::Key_2;
        ui->lineEdit->setText(str);
        break;
    case Qt::Key_3:
        str += Qt::Key_3;
        ui->lineEdit->setText(str);
        break;
    case Qt::Key_4:
        str += Qt::Key_4;
        ui->lineEdit->setText(str);
        break;
    case Qt::Key_5:
        str += Qt::Key_5;
        ui->lineEdit->setText(str);
        break;
    case Qt::Key_6:
        str += Qt::Key_6;
        ui->lineEdit->setText(str);
        break;
    case Qt::Key_7:
        str += Qt::Key_7;
        ui->lineEdit->setText(str);
        break;
    case Qt::Key_8:
        str += Qt::Key_8;
        ui->lineEdit->setText(str);
        break;
    case Qt::Key_9:
        str += Qt::Key_9;
        ui->lineEdit->setText(str);
        break;
    case Qt::Key_ParenLeft:
        str += Qt::Key_ParenLeft;
        ui->lineEdit->setText(str);
        break;
    case Qt::Key_ParenRight:
        str += Qt::Key_ParenRight;
        ui->lineEdit->setText(str);
        break;
    case Qt::Key_Plus:
        str += Qt::Key_Plus;
        ui->lineEdit->setText(str);
        break;
    case Qt::Key_Minus:
        str += Qt::Key_Minus;
        ui->lineEdit->setText(str);
        break;
    case Qt::Key_Asterisk:
        str += Qt::Key_Asterisk;
        ui->lineEdit->setText(str);
        break;
    case Qt::Key_Slash:
        str += Qt::Key_Slash;
        ui->lineEdit->setText(str);
        break;
    case Qt::Key_Comma:
        inputDot();
        break;
    case Qt::Key_Period:
        inputDot();
        break;
    case Qt::Key_Return:
        calculate();
        break;
    case Qt::Key_Backspace:
        back();
        break;
    case Qt::Key_Delete:
        erase();
        break;
    case Qt::Key_A:
        getAbs();
        break;
    case Qt::Key_L:
        getLn();
        break;
    case Qt::Key_F:
        getFact();
        break;
    case Qt::Key_S:
        getSin();
        break;
    case Qt::Key_C:
        getCos();
        break;
    case Qt::Key_T:
        getTg();
        break;
    case Qt::Key_E:
        getExp();
        break;
    case Qt::Key_P:
        getPi();
        break;
    }
}

bool dot_check = true;

void MainWindow::inputSymbol() {
    QString tmp = ((QPushButton*)sender())->text();
    str += tmp;
    if (tmp == "+", "-", "*", "/")
        dot_check = true;
    ui->lineEdit->setText(str);
}

void MainWindow::inputDot() {
    if (!str.isEmpty()) {
        int pos;
        QString s = QString::number(getLastNumber(str, pos));
        if (s != "-1" && dot_check)
            if (!s.contains(Qt::Key_Period)) {
                dot_check = false;
                str += Qt::Key_Period;
                ui->lineEdit->setText(str);
            }
    }
}

void MainWindow::erase() {
    dot_check = true;
    str.clear();
    ui->lineEdit->setText(str);
}

void MainWindow::back() {
    if (!str.isEmpty()) {
        if (str[str.length() - 1] == Qt::Key_Period)
            dot_check = true;
        int sz = str.size();
        str.resize(sz-1);
        ui->lineEdit->setText(str);
    }
}

void MainWindow::calculate() {
    if (!str.isEmpty()) {
        int k1, k2;
        removeSpaces(str);
        check(str, k1, k2);
        QString s1;
        int i1, i2;
        if (k1 > 0) {
            for (int i = 0; i < k1; i++) {
                getExpression(str, s1, i1, i2);
                str.replace(i1, s1.length() + 2, QString::number(getResult(s1)));
            }
        }
        str = QString::number(getResult(str));
        ui->lineEdit->setText(str);
    }
}

void MainWindow::getSqrt() {
    if (!str.isEmpty()) {
        int pos;
        double num = getLastNumber(str, pos);
        QString s = QString::number(num);
        if (s != "-1")
            str.replace(pos, str.length() - pos, QString::number(sqrt(num)));
        ui->lineEdit->setText(str);
    }
}

void MainWindow::getSqr() {
    if (!str.isEmpty()) {
        int pos;
        double num = getLastNumber(str, pos);
        QString s = QString::number(num);
        if (s != "-1")
            str.replace(pos, str.length() - pos, QString::number(pow(num, 2)));
        ui->lineEdit->setText(str);
    }
}

void MainWindow::getFact() {
    if (!str.isEmpty()) {
        int pos;
        double num = getLastNumber(str, pos);
        int n = (int)num;
        QString s = QString::number(num);
        if (s != "-1" && n >= 0)
            str.replace(pos, str.length() - pos, QString::number(fact(n)));
        ui->lineEdit->setText(str);
    }
}

void MainWindow::getLn() {
    if (!str.isEmpty()) {
        int pos;
        double num = getLastNumber(str, pos);
        QString s = QString::number(num);
        if (s != "-1")
            str.replace(pos, str.length() - pos, QString::number(log(num)));
        ui->lineEdit->setText(str);
    }
}

void MainWindow::getAbs() {
    calculate();
    str = QString::number(abs(str.toDouble()));
    ui->lineEdit->setText(str);
}

void MainWindow::getSin() {
    if (!str.isEmpty()) {
        int pos;
        double num = getLastNumber(str, pos);
        QString s = QString::number(num);
        if (s != "-1")
            str.replace(pos, str.length() - pos, QString::number(sin(num)));
        ui->lineEdit->setText(str);
    }
}

void MainWindow::getCos() {
    if (!str.isEmpty()) {
        int pos;
        double num = getLastNumber(str, pos);
        QString s = QString::number(num);
        if (s != "-1")
            str.replace(pos, str.length() - pos, QString::number(cos(num)));
        ui->lineEdit->setText(str);
    }
}

void MainWindow::getTg() {
    if (!str.isEmpty()) {
        int pos;
        double num = getLastNumber(str, pos);
        QString s = QString::number(num);
            if (s != "-1")
                str.replace(pos, str.length() - pos, QString::number(tan(num)));
        ui->lineEdit->setText(str);
    }
}

void MainWindow::getExp() {
    if (!str.isEmpty()) {
        int pos;
        QString s = QString::number(getLastNumber(str, pos));
        if (s != QString::number(M_E)) {
            if (s != "-1")
                str.replace(pos, str.length() - pos, QString::number(M_E));
            else
                str += QString::number(M_E);
        }
    } else str = QString::number(M_E);
    ui->lineEdit->setText(str);
}

void MainWindow::getPi() {
    if (!str.isEmpty()) {
        int pos;
        QString s = QString::number(getLastNumber(str, pos));
        if (s != QString::number(M_PI)) {
            if (s != "-1")
                str.replace(pos, str.length() - pos, QString::number(M_PI));
            else
                str += QString::number(M_PI);
        }
    } else str = QString::number(M_PI);
    ui->lineEdit->setText(str);
}

