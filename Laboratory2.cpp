#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	unsigned int choice;
	double u, x, y, z, a, c;

	cout << "Please, enter value of a: ";
	cin >> a;
	cout << "\nNow value of c: ";
	cin >> c;
	cout << "\nNow value of z: ";
	cin >> z;
	cout << "\n";

	if (z > 1){																	// Вторая ветка
		cout << "Z is greater than 1 (z > 1), the calculation goes through the second branch\nx = 1/(sqrt(z-1)" << endl;
		x = pow(sqrt(z - 1), -1);
	}
	else /*if (z <= 1)*/ {															// Первая ветка
		cout << "Z is lower than 1 (z <= 1), the calculation goes through the first branch\nx = z^2 + 1" << endl;
		x = z*z + 1;
	}

	cout << "\nPlease make a choise of U:\n1.2*x\n2.x^2\n3.x/3\nAnswer: ";
	cin >> choice;

	switch (choice){

	case 1:
		cout << "\nU(x) =  2*x" << endl;
		u = 2*x;
		break;

	case 2:
		cout << "\nU(x) =  x^2" << endl;
		u = pow(x, 2);  //x*x
		break;

	case 3:
		cout << "\nU(x) =  x / 3" << endl;
		u = x / 3;
		break;

	default:
		cout << "\nPlease, enter correct number next time (1 - 3)" << endl;
		return 0;
		break;
	}

	//if (u == 0){															// Checking neither x or u equals to 0
	//	cout << "Something's wrong. Please, restart the program\n\n";
	//	return 0;
	//}

	y = a * log(fabs(x)) + exp(x) + c * pow(sin(u*u - 1), 3);

	cout << "\nY equals to " << y << endl;
	return 0;
}
