#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void removeSpaces(string &str) {
	string tmp = "";
	for (int j = 0; j < str.length(); j++) {
		if (str[j] != ' ')
			tmp += str[j];
	}
	str = tmp;
}

void shift(double arr[], string &arr1, int i, int len) {
	for (i; i < len; i++) {
		arr[i] = arr[i + 1];
		if (i != len - 1)
			arr1[i] = arr1[i + 1];
	}
}

bool check(string str, int &k1, int &k2) {
	bool boolean = true;
	k1 = 0, k2 = 0;
	for (int i = 0; i < str.length(); i++) {
		if (!(str[i] >= '0' && str[i] <= '9' || str[i] == '+', '-', '*', '/', ',', '(', ')'))
			boolean = false;
		if (str[i] == '(') k1++;
		if (str[i] == ')') k2++;
	}
	if (k1 != k2) boolean = false;
	return boolean;
}

void getExpression(string str, string &s1, int &i1, int &i2) {
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

void arrInitialize(string str, double arr_num[], string &arr_signs, int &m) {
	string s = "";
	int n = 0;
	for (int i = 0; i < str.length(); i++) {
		if ((str[i] >= '0' && str[i] <= '9' || str[i] == ',') || (str[i] == '-' && s.empty()))
			s += str[i];
		else {
			if (!s.empty()) {
				arr_num[n] = stof(s);
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
	if (!s.empty())
		arr_num[n] = stof(s);
}

double getResult(string &str) {
	double arr_num[100];
	string arr_signs;
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

int main() {
	setlocale(LC_ALL, "rus");
	int k1, k2;
	string str;
	bool input = true;
	cout << "Введите выражение: ";
	do {
		if (!input)
			cout << "\nОшибка ввода. Введите выражение заново: ";
		getline(cin, str);
		removeSpaces(str);
		input = check(str, k1, k2);
	} while (!input);
	string s1;
	int i1, i2;
	if (k1 > 0) {
		for (int i = 0; i < k1; i++) {
			getExpression(str, s1, i1, i2);
			str.replace(i1, s1.length() + 2, to_string(getResult(s1)));
		}
	}
	cout << endl << "\nРезультат: " << getResult(str) << endl;
	system("pause");
	return 0;
}
