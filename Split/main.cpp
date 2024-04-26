#include<iostream>
using namespace std;

void Print(int arr[], const int size);

void main() 
{
	//setlocale(LC_ALL, "");
	srand(time(nullptr));

	int size;
	cout << "Enter the size of the array: "; cin >> size;

	int* arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		*(arr + i) = rand() % 100;
	}

	cout << "Source array: ";
	Print(arr, size);

	// 1. Calculate the number of even and odd elements
	int evenCount = 0, oddCount = 0;
	for (int i = 0; i < size; i++)
	{
		// Ternary operator
		arr[i] % 2 == 0 ? evenCount++ : oddCount++; 
	}
	cout << "Count of even elements: " << evenCount << endl;
	cout << "Count of odd elements: " << oddCount << endl;

	// 2. Allocating memory for arrays
	int* even = new int[evenCount];
	int* odd = new int[oddCount];

	// 3. Copy even and odd elements to the corresponding arrays
	for (int i = 0, j = 0, k = 0; i < size; i++)
	{
		// i - counter for the source arr
		// j - counter for the even arr
		// k - counter for the odd arr
		//(arr[i] % 2 == 0 ? even[j++] : odd[k++]) = arr[i];
		// в инкриментах используется постфиксная форма
		// delete единственный оператор не возвращающий значений
		// сначала отрабатывает оператор индксирования, после оператор инкремента

		(arr[i] % 2 ? odd[k++] : even[j++]) = arr[i];
	}

	// 4. Output of results
	cout << "Even numbers: ";
	Print(even, evenCount);
	cout << "Odd numbers: ";
	Print(odd, oddCount);
	
	// 5. Delete arrays
	delete[] arr;
	delete[] even;
	delete[] odd;
}

void Print(int arr[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}