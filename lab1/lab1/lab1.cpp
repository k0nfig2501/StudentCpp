// Lab1.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	char agreement = 'y';
	do {
		float num1, num2;
		cout << "\nEnter two numbers please:" << endl;
		cin >> num1 >> num2;
	        while (cin.fail()) {
			cout << "\nIncorrect input.Try again\n";
			cin.clear();
			cin.ignore(10000, '\n');
			cin >> num1 >> num2;
		}
		cout << "\nWhat do you want to do?" << endl
			<< "1. +" << endl
			<< "2. -" << endl
			<< "3. *" << endl
			<< "4. /" << endl
			<< " Next operations wiil be available for the first number " << endl
			<< "5. Sqrt" << endl
			<< "6. Sqr" << endl
			<< "7. Log (a,b)" << endl;

		int command;
		cin >> command;
		while (cin.fail()) {
			cout << "\nIncorrect command.Try again\n";
			cin.clear();
			cin.ignore(10000, '\n');
			cin >> command;
		}
		cout << "Your answer: " << command << endl;

		float result;
		switch (command) {
		case 1:
			result = num1 + num2;
			cout << "Result: " << result;
			break;

		case 2:
			result = num1 - num2;
			cout << "Result: " << result;
			break;

		case 3:
			result = num1 * num2;
			cout << "Result: " << result;
			break;

		case 4:
			result = num1 / num2;
			cout << "Result: " << result;
			break;

		case 5:
			if (num1 >= 0) {
				result = sqrt(num1);
				cout << "Result: " << result;
			}
			else
				cout << "Incorrect operation\n";
			break;

		case 6:
			result = num1 * num1;
			cout << "Result: " << result;
			break;

		case 7:
			if ((num1 > 0) && (num2 > 0) && (num1 != 1)) {
				result = log(num2) / log(num1);
				cout << "Result: " << result;
			}
			else
				cout << "Incorrect operation";
			break;

		default:
			cout << "You entered an incorrect number. Try again";
		}

		cout << "\nDo you want to try again? y/n\n";
		cin >> agreement;
	} while (agreement == 'y');

	return 0;
}
