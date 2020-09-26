// Задание №1
// Методичка по ОАИП
// БГУИР 2007 год

#define   _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <iomanip>      // std::setprecision and std::cin.ignore


using namespace std;

long double fac(int n)													// функция вычисления факториала
{
	long double temp = 1;
	if (n == 0) {
		return 1;
	} else {
		for (int i = 1; i <= n; i++) {
			temp *= i;
		}
		return temp;
    }
}

int main()
{
	int n, des;
	double y, res, a, b, h, x;
	long double s = 1.;
	long double r = 1;


	cout << "1.Get standart a,b,h,n\n2.Set custom a,b,h,n\nDecision: ";
	cin >> des;
	cout << "\n";

	switch (des){

	case 1:																// Присвоение стандартных значений
		a = 0.1;
		b = 1.0;
		h = 0.1;
		n = 16;
		cout << "a = 0,1; b = 1,0; h = 0,1; n = 14";
		break;

	case 2:																// Кастомные значения
		while (true) {
			cout << "Please, enter a, b, h, n by the space\n ";
			cin >> a >> b >> h >> n;

			if (cin.fail()) {
				cout << "Incorrect input. Try again\n\n";
				cin.clear();
				cin.ignore(1000, '\n');
			} else {
				break;
			}
		}
		break;

	default:															// Ошибка ввода
		cout << "Incorrect answer. Numbers set to default\n";
		a = 0.1;
		b = 1.0;
		h = 0.1;
		n = 16;
		break;
	}

	if (n > 170 || n < 0)
	{
		cout << "\nIncorrect n number. Number is set to default - 16.\n";
		n = 16;
	}

	cout << "\n\n"
			 "X\tSum(x)\tY(x)\t|Y - S|\n";

	for (x = a; x <= b; x += h){										// Вычисление и вывод таблицы значений функции

		y = cos(x * sin(M_PI / 4)) * exp(x * cos(M_PI / 4));
		
		for (int k = 1; k <= n; ++k) {
			r *= x / k;
			s += cos(k * M_PI/ 4) * r;
		}

		cout << x << "\t";
		cout << setprecision(4) << s << "\t";
		cout << setprecision(4) << y << "\t";
		cout << setprecision(4) << fabs(y - s) << "\n";
		r = 1;
		s = 1.;
	}

	return 0;
}