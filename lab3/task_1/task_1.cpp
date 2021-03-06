// task_1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void removeSpaces(char *str) {
	int k = 0;
	for (int j = 0; j < strlen(str); j++)
	{
		if (str[j] == '.')
			str[j] = ',';
		if (str[j] != ' ')
		{
			str[k] = str[j];
			k++;
		}
	}
	str[k] = '\0';
}

void shift(double* arr, char* arr1, int p, int len) {
	for (p; p < len; p++) {
		arr[p] = arr[p + 1];
		if (p != len - 1)
			arr1[p] = arr1[p + 1];
	}
}

bool check(char* str) {
	bool boolean = true;
	for (int i = 0; i < 100; i++)
		if ((str[i] >= '0' && str[i] <= '9' || str[i] == '+', '-', '*', '/', ',') == false)
			boolean = false;
	return boolean;
}

double getResult(char* str) {
	char* arr_signs = new char[100], *s = new char[20];
	double* arr_num = new double[100];
	int n = 0, m = 0, f = 0;
	for (int i = 0; i < strlen(str); i++) {
		if ((str[i] >= '0' && str[i] <= '9' || str[i] == ',') || (str[i] == '-' && f == 0)) {
			s[f] = str[i];
			f++;
		}
		else {
			s[f] = '\0';
			f = 0;
			if (strlen(s) > 0) {
				arr_num[n] = atof(s);
				n++;
			}
			if (str[i] == '+', '-', '*', '/') {
				if (str[i] == '-') {
					s[f] = str[i];
					f++;
					arr_signs[m] = '+';
					m++;
				}
				else {
					arr_signs[m] = str[i];
					m++;
				}
			}
		}
	}
	s[f] = '\0';
	if (f != 0) {
		arr_num[n] = atof(s);
		n++;
	}

	int k = 0;
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
	delete[] arr_num, arr_signs, s;
	return res;
}

int main() {
	setlocale(LC_ALL, "rus");
	char* str = new char[100];
	bool input = true;
	cout << "Введите выражение: ";
	do {
		if (input == false)
			cout << "\nОшибка ввода. Введите выражение заново: ";
		cin.getline(str, 100);
		removeSpaces(str);
		input = check(str);
	} while (input == false);

	cout << "\nРезультат: " << getResult(str) << endl;
	delete[] str;
	system("pause");
	return 0;
}