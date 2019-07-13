#include "calculator.h"

void removeSpaces(QString &str) {
    QString tmp = "";
    for (int j = 0; j < str.length(); j++) {
        if (str[j] != ' ')
            tmp += str[j];
    }
    str = tmp;
}

void shift(double arr[], QString &arr1, int i, int len) {
    for (i; i < len; i++) {
        arr[i] = arr[i + 1];
        if (i != len - 1)
            arr1[i] = arr1[i + 1];
    }
}

bool check(QString str, int &k1, int &k2) {
    bool boolean = true;
    k1 = 0; k2 = 0;
    for (int i = 0; i < str.length(); i++) {
        if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '+', '-', '*', '/', '.', '(', ')'))
            boolean = false;
        if (str[i] == '(') k1++;
        if (str[i] == ')') k2++;
    }
    if (k1 != k2) boolean = false;
    return boolean;
}

void getExpression(QString str, QString &s1, int &i1, int &i2) {
    bool f = false;
    s1 = "";
    for (int j = 0; j < str.length(); j++) {
        if (str[j] == '(') i1 = j;
        if (str[j] == ')' && f == false) {
            i2 = j;
            f = true;
        }
    }
    for (int j = i1 + 1; j < i2; j++)
        s1 += str[j];
}

void arrInitialize(QString str, double arr_num[], QString &arr_signs, int &m) {
    QString s = "";
    int n = 0;
    for (int i = 0; i < str.length(); i++) {
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.' || (str[i] == '-' && s.isEmpty()))
            s += str[i];
        else {
            if (!s.isEmpty()) {
                arr_num[n] = s.toDouble();
                n++;
            }
            s = "";
            if (str[i] == '+', '-', '*', '/') {
                if (str[i] == '-') {
                    s += str[i];
                    arr_signs += '+';
                    m++;
                }
                else {
                    arr_signs += str[i];
                    m++;
                }
            }
        }
    }
    if (!s.isEmpty())
        arr_num[n] = s.toDouble();
}

double getLastNumber(QString str, int &pos) {
    QString s = "";
    pos = 0;
    if (str[str.length() - 1] == Qt::Key_ParenRight) {
        int k1, k2;
        removeSpaces(str);
        check(str, k1, k2);
        int i1, i2;
        if (k2 > 0)
            for (int i = 0; i < k2; i++) {
                getExpression(str, s, i1, i2);
                str.replace(i1, s.length() + 2, QString::number(getResult(s)));
                if (i == k2 - 1) pos = i1;
            }
    }
    s = "";
    for (int i = str.length() - 1; i >= 0 ; i--)
        if ((str[i] >= Qt::Key_0 && str[i] <= Qt::Key_9) || str[i] == Qt::Key_Period)
            s.prepend(str[i]);
        else {
            pos = str.length() - s.length();
            break;
        }
    if (s.isEmpty())
        return static_cast<double>(-1);
    else return s.toDouble();
}

unsigned int fact(int n) {
    if (n > 1)
        return n * fact(n - 1);
    if (n == 0 || n == 1)
        return 1;
}

double getResult(QString &str) {
    double arr_num[100];
    QString arr_signs;
    int m = 0, k = 0;
    arrInitialize(str, arr_num, arr_signs, m);
    for (int j = 0; j < m; j++)
        if (arr_signs[j] == '*' || arr_signs[j] == '/') k++;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < m; j++) {
            if (arr_signs[j] == '*') {
                arr_num[j + 1] *= arr_num[j];
                shift(arr_num, arr_signs, j, m);
                break;
            }
            else if (arr_signs[j] == '/') {
                arr_num[j + 1] = arr_num[j] / arr_num[j + 1];
                shift(arr_num, arr_signs, j, m);
                break;
            }
        }
    k = m - k;
    double res = arr_num[0];
    for (int j = 0; j < k; j++)
        res += arr_num[j + 1];
    return res;
}
