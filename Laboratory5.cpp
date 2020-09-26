#define MAX_RANGE 1000
#define MAX_ARR 256

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int min(int*, int);												// Поиск индекса минимального числа в массиве
int max(int*, int);												// Поиск индекса максимального числа в массиве				
int ffneg_num(int*, int);										// Поиск первого отрицательного числа в массиве
int flneg_num(int*, int);										// Поиск последнего отрицательного числа в массиве
int nn_check(int*, int);										// Проверка наличия отрицательных чисел
int get_int(void);												// Функция "проверки на дурака"

int main() {
	srand((unsigned)time(0));									// Инициализация псевдо-случайных чисел

	long double result;
	int* a;
	int user_decision, array_size, seed, i, err;
	i = 0;
	result = 1;
	err = 1;

	cout << "Enter array size (answer should be integer) : ";
	array_size = get_int();

	while (err) {											// Get only positive number
		if (array_size <= 0) {
			err = 1;
			cout << "Incorrect input. Try again: ";
			array_size = get_int();
		}
		else
			err = 0;
	}

	cout << "The array contains " << array_size << " elements\n";
	a = new int[array_size];

	cout << "\n!! If decision input is incorrect. Elements will be randomised !!\n";
	cout << "\nPlease make a choice:\n1.Set elements of array to random\n2.Set custom elements\n"
		<< "Decision: ";
	cin >> user_decision;

	switch (user_decision)
	{

	case 1: default:																								// Ввод случайных данных в указанных границах
		int low_bound, top_bound;
		cout << "\nSelect range of number. Make sure, that the first number should be greater than second\n";
																	// И снова он
		cout << "Low bound: ";
		low_bound = get_int();
			
		cout << "Top bound: ";
		top_bound = get_int();

		if (top_bound <= low_bound) {
			cout << "Top is less, or equals to low bound. Elements will be randomised between (-10 - 10)\n";
			low_bound = -10;
			top_bound = 10;
		}

		cout << "Numbers will be randomised in range [" << low_bound << ", " << top_bound << "]\n\n";

		seed = top_bound - low_bound + 1;													// rand() % 25 = (0 - 24), но rand() % 25 + 1 = (1 - 25)
		for (int i = 0; i < array_size; ++i)
			a[i] = low_bound + (rand() % seed);
		break;

	case 2:																// Ввод данных массива с клавиатуры
		cout << "Please, enter your numbers:\n";
		for (int i = 0; i < array_size; ++i) {
			cout << "\na[" << i << "] = ";
			a[i] = get_int();
		}
		break;
		}

		cout << "Source Array:";
		cout << "\nA[" << array_size << "] = { ";
		for (int i = 0; i < array_size; ++i)
			cout << a[i] << " ";
		cout << "}\n";

		if (nn_check(a, array_size)) {																				// Задание 16 с отрицательными числами

			cout << "\nFirst Negative Number: " << ffneg_num(a, array_size) << ". a[num] = " << a[ffneg_num(a, array_size)] << endl;
			cout << "\nLast negative Number: " << flneg_num(a, array_size) << ". a[num] = " << a[flneg_num(a, array_size)] << endl;

			for (int i = ffneg_num(a, array_size); i <= flneg_num(a, array_size); ++i)
				result *= a[i];

			cout << "\nResult is " << result << endl;
		}
		else {											// Задание 1 с поиском min и max
			cout << "\nNo negative numbers found. Calculating Exercise Number 1\n";
			int max_ind = max(a, array_size);
			int min_ind = min(a, array_size);

			cout << "Max Array Ind: " << max_ind << ". a[num] = " << a[max_ind] << endl;
			cout << "Min Array Ind: " << min_ind << ". a[num] = " << a[min_ind] << endl;

			if (max_ind < min_ind) {
				for (int i = max_ind; i <= min_ind; ++i) {
					result *= a[i];
				}
			}
			else {
				for (int i = min_ind; i <= max_ind; ++i)
					result *= a[i];
			}

			cout << "\nResult is " << result << endl;
		}

	delete[]a;
	return 0;
}

int max(int* array, int array_size) {																// Find Max Array Value
	int temp_max{};
	int max_val = array[0];
	for (int i = 0; i < array_size; ++i)
	{
		if (max_val < array[i]) {
			max_val = array[i];
			temp_max = i;
		}
	}
	return temp_max;
}

int min(int* array, int n) {																	// Find Min Array Value
	int temp_min{};
	int min_val = array[0];
	for (int i = 0; i < n; ++i) {
		if (min_val > array[i]) {
			min_val = array[i];
			temp_min = i;
		}
	}
	return temp_min;
}

int nn_check(int* array, int array_size) {													// Check, whether there is negative numbers in array or not 
	for (int i = 0; i < array_size; ++i) {
		if (array[i] < 0)
			return 1;
	}
	return 0;
}

int ffneg_num(int* array, int array_size) {												// Find First Negative number;
	int i = 0;
	while (array[i] >= 0 && i < array_size)
		i++;
	return i;
}

int flneg_num(int* array, int array_size) {													// Find last negative number
	int temp = array_size - 1;
	while (array[temp] >= 0 && temp >= 0)
		--temp;
	return temp;
}

int get_int()											// "проверка на дурака" v.2
{
	int result = 0;
	char c_space[MAX_ARR];
	char* temp;
	int err = 1;
	while (err) {
		cin >> c_space;
		cin.clear();
		cin.ignore(MAX_RANGE, '\n');
		size_t len = strlen(c_space);													// size_t = unsigned int 
		temp = new char[len];
		result = atoi(c_space);															// convert char into int

		for (unsigned int i = 0; i < len; i++) {
			err = 0;
			if (i == 0 && (c_space[i] == '-' || c_space[i] == '+'));												// Получение знака числа;
			else if (!isdigit((unsigned char)c_space[i]) && c_space[i] != '.') {									// Получение числа с плавающей точкой и экспоненциальной формы (in progress)
				cout << "Incorrect input. Try again: ";
				err = 1;
				break;
			}
		}
	}
	delete[] temp;
	return result;
}

