#include<iostream>
using namespace std;

void Print(int arr[], const unsigned int n);
void Print(int** arr, const int rows, const int cols);
void FillRand(int arr[], const unsigned int n);
void FillRand(int** arr, const int rows, const int cols);
int* push_back(int arr[], unsigned int& n, int value);
//#define DINAMIC_MEMORY_1
#define DINAMIC_MEMORY_2
void main()
{
	setlocale(LC_ALL, "");
#ifdef DINAMIC_MEMORY_1
	unsigned int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добовляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	delete[] arr;
#endif // DINAMIC_MEMORY_1
	int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}
	delete[] arr;
}

void Print(int arr[], const unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;

}
void FillRand(int arr[], const unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
int* push_back(int arr[], unsigned int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[]arr;
	arr = buffer;//перезаписываем адрес старого массива адресом нового массива

	arr[n] = value;
	n++;//массив увеличили на 1
	return arr;
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}cout << endl;
	}
}
