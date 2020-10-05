// Задание 7 
// В матрице размером N x M упорядочить строки по возрастанию их первых элементов.

#include <iostream>
#include <iomanip>

int get_int(void);					// "проверка на дурака" v.2
int partition(int**, int, int);		// основная функция для сортировки элементов массива
void quicksort(int**, int, int);	// функция для вызыва partion рекурсивно
void printMatrix(int**, int);		// функция вывода матрицы

int main() {
	srand((unsigned)time(NULL));	// init random seed

	int** a;
	int size;

	std::cout << "Please, select square matrix size: ";    // Size user input
	size = get_int();
	while (size < 0) {
		std::cout << "Incorrect input. Try again: ";
		size = get_int();
	}

	a = new int* [size];								   // Memory allocation for rows
	for (int i = 0; i < size; i++) a[i] = new int[size];   //					for cols

	// Get random array elements
	for (int i = 0; i < size; i++)
		for (int n = 0; n < size; n++)
			a[i][n] = rand() % 40 + 1;



	// Source matrix print
	std::cout << "\n\n		* Source Array *\n\n";
	printMatrix(a, size);
	
	// Sort matrix
	quicksort(a, 0, size - 1);						

	// Print modded matrix
	std::cout << "\n		* Modded Array *\n\n";
	printMatrix(a, size);
	
	// Clear all the garbage :) that we left
	delete[]a;
	return 0;
}

int partition(int** arr, int low, int high)
{
	int pivot = arr[high][0];				// set pivot to the end index
	int i = low - 1;						// set start element
	int* swap;

	for (int j = low; j <= high - 1; j++)
	{
											// If current element is smaller than the pivot  
		if (arr[j][0] < pivot)
		{
			i++;							// skiping to next position for lower number than pivot
			swap = arr[i];					// swap selected number 
			arr[i] = arr[j];
			arr[j] = swap;
		}
	}
	swap = arr[i + 1];						// swaping pivot to it's sorted place 
	arr[i + 1] = arr[high];
	arr[high] = swap;
	return (i + 1);							// return i + 1	
}


void quicksort(int** arr, int low, int high) 
{
	if (low < high)							// do recursion until it's sorted

	{
		int pi = partition(arr, low, high);	// pi is item in the right place.

		quicksort(arr, low, pi - 1);		// do it for both sides of pivot
		quicksort(arr, pi + 1, high);		// 
	}
}

void printMatrix(int** arr, int size)
{
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			std::cout << std::setw(4) << arr[i][j];
		}
		std::cout << "\n";
	}
}

int get_int(void)											// "проверка на дурака" v.2
{
	int result = 0;
	char c_space[256];
	char* temp;
	int err = 1;
	while (err) {
		std::cin >> c_space;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		size_t len = strlen(c_space);													// size_t = unsigned int 
		temp = new char[len];
		result = atoi(c_space);															// convert char into int

		for (unsigned int i = 0; i < len; i++) {
			err = 0;
			if (i == 0 && (c_space[i] == '-' || c_space[i] == '+'));												// Получение знака числа;
			else if (!isdigit((unsigned char)c_space[i]) && c_space[i] != '.') {									// Получение числа с плавающей точкой и экспоненциальной формы (in progress)
				std::cout << "Incorrect input. Try again: ";
				err = 1;
				break;
			}
		}
	}
	delete[] temp;
	return result;
}