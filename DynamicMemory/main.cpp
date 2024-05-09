#include<iostream>
using namespace std;

#define tab "\t"
//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value);
int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
void insert(int arr[], const int n, int index, int value);
int* erase(int arr[], int& n, int index);

void main()
{
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY_1
	/* 1 version
	int n;
	cout << "Введите размер массива: "; cin >> n;

	int* arr = new int[n];
	
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение: "; cin >> value;

	int* arrWithValue = new int[n + 1];

	for (int i = 0; i < n; i++)
	{
		arrWithValue[i] = arr[i];
	}
	arrWithValue[n] = value;

	Print(arrWithValue, n + 1);

	delete[] arr;
	delete[] arrWithValue;*/

	// 2 version
	int n;
	cout << "Введите размер массива: "; cin >> n;

	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	cout << "Массив без последнего элемента: ";
	arr = pop_back(arr, n);
	Print(arr, n);

	cout << "Массив без первого элемента: ";
	arr = pop_front(arr, n);
	Print(arr, n);

	int index;
	do
	{
		cout << "Введите индекс элемента, значение которого хотите заменить: "; cin >> index;
		if (index > n) cout << "Индекс не может быть больше, чем всего элементов в массиве!" << endl;
	} while (index > n);

	cout << "Введите добавляемое значение: "; cin >> value;

	insert(arr, n, index, value);
	Print(arr, n);

	do
	{
		cout << "Введите индекс элемента, который хотите удалить: "; cin >> index;
		if (index > n) cout << "Индекс не может быть больше, чем всего элементов в массиве!" << endl;
	} while (index > n);

	arr = erase(arr, n, index);
	Print(arr, n);

	delete[] arr; 
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2

#endif // DYNAMIC_MEMORY_2

}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
int* push_back(int arr[], int& n, int value)
{
	// 1. Create buffer array
	int* buffer = new int[n + 1];

	// 2. Copy elements
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	// 3. Delete source array
	delete[] arr;

	// 4. Replace the address of the source array with the address of the new array
	arr = buffer;

	// 5. Only after that, there was free space at the end of the array for the new value
	arr[n] = value;
	n++;

	return arr;
}
int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1];

	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;

	buffer[0] = value;
	n++;

	return buffer;
}
int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
int* pop_front(int arr[], int& n) 
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
void insert(int arr[], const int n, int index, int value)
{
	for (int i = 0; i < n; i++) 
		if (i == index) arr[i] = value;
}
int* erase(int arr[], int& n, int index)
{
	int* buffer = new int[n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	for (int i = index; i < n; i++) buffer[i] = buffer[i + 1];
	n--;
	delete[] arr;
	return buffer;
}