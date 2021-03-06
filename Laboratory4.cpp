﻿#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>

using namespace std;

double func_y(double, int);																					// Y(x)
double func_s(double, int);																					// Sum(x)
double func_abs(double, int);																				// |Y(x) - Sum(x)|
void printFunc(double a, double b, double h, int n, const char* text, double (*ff)(double, int));			// Function, that prints functions :)

int main() {
	int n, des, des_1;
	double a, b, h;

	cout << "1.Get standart a,b,h,n\n2.Set custom a,b,h,n\nDecision: ";
	cin >> des;

	cout << "\n";

	switch (des) {
	case 1:																									// Присвоение стандартных значений
		a = 0.1;
		b = 1.0;
		h = 0.1;
		n = 14;
		cout << "a = 0,1; b = 1,0; h = 0,1; n = 14";
		break;

	case 2:																									// Присвоение данных, вводимых с клавиатуры
		while (true) {
			cout << "Please, enter a, b, h, n by the space or enter: ";
			cin >> a >> b >> h >> n;

			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Incorrect input. Try again\n";
			}
			else {
				break;
			}
		}
		cin.ignore(1000, '\n');
		break;

	default:																								// Ошибка выбора
		cout << "Incorrect input. Calculating standart a,b,h,n\n";
		a = 0.1;
		b = 1.0;
		h = 0.1;
		n = 14;
		break;
	}

	cout << "\n\n"
		<< "Choose what you want to calculate:\n"
		<< "1. Sum(x)\n2. Y(x)\n3. |Y(x) - Sum(x)|\nDesicion: ";

	cin >> des_1;

	switch (des_1) {																						// Choose function
	case 1: default:																					// Sum(x)
		printFunc(a, b, h, n, "\nS(x):\n", func_y);
		break;
	case 2:																								// Y(x)
		printFunc(a, b, h, n, "\nY(x):\n", func_s);
		break;

	case 3:																								// |Y(x) - Sum(x)|
		printFunc(a, b, h, n, "\n|Y - Sum(x)|:\n", func_abs);
		break;
	}

	return 0;
}



double func_y(double x, int n) { return cos(x * sin(M_PI / 4)) * exp(x * cos(M_PI / 4)); }				// Y(x)

double func_s(double x, int n) {																		// Sum(x)
	long double s = 1.;
	long double r = 1.;

	for (int k = 1; k <= n; ++k) {
		r *= x / k;
		s += cos(k * M_PI / 4) * r;
	}

	return s;
}

double func_abs(double x, int n) { return fabs(func_y(x, n) - func_s(x, n)); }							// |Y(x) - Sum(x)|

void printFunc(double a, double b, double h, int n, const char* text, double (*ff)(double, int))
{
	cout << text;
	for (double x = a; x <= b; x += h)
		cout << "With x = " << x << ". Solution is " << ff(x, n) << "\n";
}