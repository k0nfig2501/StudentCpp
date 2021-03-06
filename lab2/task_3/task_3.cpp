
#include "stdafx.h"
#include <iostream>
using namespace std;

void RemoveSpaces(char *str)												
{
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

int ZeroCheck(char s[])													
{
	int p = 0;
	for (int f = 0; f < strlen(s); f++)
	{
		if ((s[f] != '0') && (s[f] != ','))
			return 0;
		else if (s[f] == '0') p++;
	}
	if (p != 0)
		return 1;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите выражение : " << endl;
	char *str = new char[100], *str1 = new char[100], *str2 = new char[100];
	int  index = -1, i = 0, l = 0;
	double num1, num2;
	char sign, buff;
input:
	cin.getline(str, 100);
	RemoveSpaces(str);
	i = 0;
	if (str[0] == '-')
		i++;

	for (i; i < strlen(str); i++)
		if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/'))
		{
			index = i;
			break;
		}
	if (index != -1)
		sign = str[index];
	for (int m = 0; m < index; m++)
		str1[m] = str[m];
		 
	l = 0;
	for (int n = index + 1; n < strlen(str); n++)
	{
		str2[l] = str[n];
		l++;
	}
	num1 = atof(str1);
	num2 = atof(str2);
	if (((num1 / 1 != NULL) || (ZeroCheck(str1) == 1))
		&& ((num2 / 1 != NULL) || (ZeroCheck(str2) == 1)) && (index != 0) == true)
		delete[] str, str1, str2;
	else {
		cout << "Некорректный ввод. Попробуйте заново\n" << endl;
		goto input;
	}

	switch (sign) {
	case '+':
		cout << "Результат : " << num1 + num2 << endl;
		break;
	case '-':
		cout << "Результат : " << num1 - num2 << endl;
		break;
	case '*':
		cout << "Результат : " << num1 * num2 << endl;
		break;
	case '/':
		cout << "Результат : " << num1 / num2 << endl;
		break;
	}
	cout << "\nНажмите любую клавишу для завершения программы\n";
	system("pause");
	return 0;
}