#include<iostream>
using namespace std;

#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");

	int n;
	cout << "¬ведите размер массива: "; cin >> n;

	int* arr = new int[n];
	
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "¬ведите добавл€емое значение: "; cin >> value;

	int* arrWithValue = new int[n + 1];

	for (int i = 0; i < n; i++)
	{
		arrWithValue[i] = arr[i];
	}
	arrWithValue[n] = value;

	Print(arrWithValue, n + 1);

	delete[] arr;
	delete[] arrWithValue;
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