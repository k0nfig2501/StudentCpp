#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QString>

void removeSpaces(QString &str);
void shift(double arr[], QString &arr1, int i, int len);
bool check(QString str, int &k1, int &k2);
void getExpression(QString str, QString &s1, int &i1, int &i2);
void arrInitialize(QString str, double arr_num[], QString &arr_signs, int &m);
double getLastNumber(QString str, int &pos);
double getResult(QString &str);
unsigned int fact(int n);

#endif
