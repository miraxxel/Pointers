#include<iostream>
using namespace std;

void main() 
{
	setlocale(LC_ALL, "");
	srand(time(nullptr));

	int size, evenCount = 0, oddCount = 0;
	cout << "������� ������ �������: "; cin >> size;

	int* arr = new int[size]; 
	int* even = new int[size];
	int* odd = new int[size];

	for (int i = 0; i < size; i++)
	{
		*(arr + i) = rand() % 100;
	}

	cout << "�������� ������: ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] % 2 == 0) {
			even[evenCount] = arr[i];
			evenCount++;
		}
		else {
			odd[oddCount] = arr[i];
			oddCount++;
		}
	}

	cout << "������ even (� ������� �������): ";
	for (int i = 0; i < evenCount; i++)
	{
		cout << even[i] << " ";
	}
	cout << endl;

	cout << "������ odd (� ��������� �������): ";
	for (int i = 0; i < oddCount; i++)
	{
		cout << odd[i] << " ";
	}
	cout << endl;

	delete[] arr;
	delete[] even;
	delete[] odd;
}