#include<iostream>
using namespace std;

#define tab "\t"
//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, int value);
void push_col_back(int**& arr, int rows, int& cols);
int* push_front(int arr[], int& n, int value);
void push_row_front(int**& arr, int& rows, int cols);

int* pop_back(int arr[], int& n);
void pop_row_back(int**& arr, int& rows, int cols);
void pop_col_back(int**& arr, int rows, int& cols);
int* pop_front(int arr[], int& n);
void pop_row_front(int**& arr, int& rows, int cols);
void push_col_front(int**& arr, int rows, int& cols);

void insert(int arr[], const int n, int index, int value);
void insert_row(int**& arr, int& rows, int cols, int indexRow);
void insert_col(int**& arr, int rows, int& cols, int indexCol);

int* erase(int arr[], int& n, int index);
void erase_row(int**& arr, int& rows, int cols, int indexRowDel);

void Allocate(int** arr, const int rows, const int cols);
void Clear(int** arr, const int rows, const int cols);

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

	int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки (столбцов): "; cin >> cols;

	// 1. Создаем (объявляем) массив указателей
	int** arr = new int*[rows];
	// 2. Выделяем память под строки
	Allocate(arr, rows, cols);

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Добавление строки в начало массива: " << endl;
	push_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	int indexRow;
	do
	{
		cout << "Введите индекс строки, куда хотите вставить новую строку: "; cin >> indexRow;
		if (indexRow > rows) cout << "Индекс не может быть больше, чем всего строк в массиве!" << endl;
	} while (indexRow > rows);
	insert_row(arr, rows, cols, indexRow);
	Print(arr, rows, cols);

	cout << "Массив без последней строки:" << endl;
	pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Массив без первой строки:" << endl;
	pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	do
	{
		cout << "Введите индекс строки, которую хотите удалить: "; cin >> indexRow;
		if (indexRow > rows) cout << "Индекс не может быть больше, чем всего строк в массиве!" << endl;
	} while (indexRow > rows);
	erase_row(arr, rows, cols, indexRow);
	Print(arr, rows, cols);

	cout << "Массив с добавленным столбцом в конец: " << endl;
	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Массив с добавленным столбцом в начало: " << endl;
	push_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	int indexCol;
	do
	{
		cout << "Введите индекс столбца (элемента строки), куда хотите вставить новый столбец: "; cin >> indexCol;
		if (indexCol > cols) cout << "Индекс не может быть больше, чем всего столбцов в массиве!" << endl;
	} while (indexCol > cols);
	insert_col(arr, rows, cols, indexCol);
	Print(arr, rows, cols);

	cout << "Массив без последнего столбца:" << endl;
	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	Clear(arr, rows, cols);
	
#endif // DYNAMIC_MEMORY_2
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
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

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
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
void push_col_back(int**& arr, int rows, int& cols)		// Добавляет столбец в конец массива
{
	// генерируем добавляемый столбец
	int* newCol = new int[rows];
	FillRand(newCol, rows);

	// создаем новый массив с увеличенным на 1 количеством столбцов
	int** buffer = new int* [cols + 1];
	Allocate(buffer, rows, cols + 1);

	// копируем значения в новый массив из исходного
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			buffer[i][j] = arr[i][j];
		}
	}
	// вставляем сгенерированный столбец в конец массива
	for (int i = 0; i < rows; ++i)
	{
		buffer[i][cols] = newCol[i];
	}

	// подставляем новый массив на место старого
	arr = buffer;
	cols++;
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
void push_row_front(int**& arr, int& rows, int cols)	// Добавляет строку в начало массива
{
	// генерируем добавляемую строку
	int* newRow = new int[cols];
	FillRand(newRow, cols);

	// создаем новый массив с увеличенным на 1 количеством строк
	int** buffer = new int* [rows + 1];
	Allocate(buffer, rows + 1, cols);

	// копируем значения в новый массив из исходного со смещением на 1
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			buffer[i + 1][j] = arr[i][j];
		}
	}
	// вставляем сгенерированную строку на освободившееся место
	for (int j = 0; j < cols; ++j)
	{
		buffer[0][j] = newRow[j];
	}

	// освобождаем память
	//Clear(arr, rows, cols);
	
	// подставляем новый массив на место старого
	arr = buffer;
	rows++;
}
void push_col_front(int**& arr, int rows, int& cols)	// Добавляет столбец в начало массива
{
	// генерируем добавляемый столбец
	int* newCol = new int[rows];
	FillRand(newCol, rows);

	// создаем новый массив с увеличенным на 1 количеством столбцов
	int** buffer = new int* [cols + 1];
	Allocate(buffer, rows, cols + 1);

	// копируем значения в новый массив из исходного со смещением на 1
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			buffer[i][j + 1] = arr[i][j];
		}
	}

	// вставляем сгенерированный столбец в конец массива
	for (int i = 0; i < rows; ++i)
	{
		buffer[i][0] = newCol[i];
	}

	// подставляем новый массив на место старого
	arr = buffer;
	cols++;
}

int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
void pop_row_back(int**& arr, int& rows, int cols) // Удаляет последнюю строку из массива
{
	// создаем новый массив с количеством строк уменьшенным на 1 
	int** buffer = new int* [rows - 1];
	Allocate(buffer, rows - 1, cols);

	// копируем значения в новый массив из исходного 
	for (int i = 0; i < rows - 1; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			buffer[i][j] = arr[i][j];
		}
	}
	// обновляем ссылки на массив и количество строк
	arr = buffer;
	rows--;
}
void pop_col_back(int**& arr, int rows, int& cols)		// Удаляет последний столбец из массива
{
	// создаем новый массив с количеством стобцов уменьшенным на 1 
	int** buffer = new int* [cols - 1];
	Allocate(buffer, rows, cols - 1);

	// копируем значения в новый массив из исходного 
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols - 1; ++j)
		{
			buffer[i][j] = arr[i][j];
		}
	}
	// обновляем ссылки на массив и количество столбцов
	arr = buffer;
	cols--;
}
int* pop_front(int arr[], int& n) 
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
void pop_row_front(int**& arr, int& rows, int cols) // Удаляет нулевую строку из массива
{
	// освобождаем память под первую строку
	delete[] arr[0];

	// создаем новый массив с количеством строк уменьшенным на 1 
	int** buffer = new int* [rows - 1];
	Allocate(buffer, rows - 1, cols);

	// копируем значения в новый массив из исходного 
	for (int i = 1; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			buffer[i - 1][j] = arr[i][j];
		}
	}
	// обновляем ссылки на массив и количество строк
	arr = buffer;
	rows--;
}

void insert(int arr[], const int n, int index, int value)
{
	for (int i = 0; i < n; i++) 
		if (i == index) arr[i] = value;
}
void insert_row(int**& arr, int& rows, int cols, int indexRow)
{
	// генерируем добавляемую строку
	int* newRow = new int[cols];
	FillRand(newRow, cols);

	// создаем новый массив с увеличенным на 1 количеством строк
	int** buffer = new int* [rows + 1];
	Allocate(buffer, rows + 1, cols);

	// копируем значения в новый массив из исходного со смещением на 1 в нужном месте
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (i >= indexRow)
				buffer[i + 1][j] = arr[i][j];
			else
				buffer[i][j] = arr[i][j];
		}
	}

	// добавляем строку в массив
	for (int j = 0; j < cols; ++j) buffer[indexRow][j] = newRow[j];

	// обновляем ссылки на массив и количество строк
	arr = buffer;
	rows++;
}
void insert_col(int**& arr, int rows, int& cols, int indexCol)		// Вставляет столбец в массив по указанному индексу
{
	// генерируем добавляемый столбец
	int* newCol = new int[rows];
	FillRand(newCol, rows);

	// создаем новый массив с увеличенным на 1 количеством столбцов
	int** buffer = new int* [cols + 1];
	Allocate(buffer, rows, cols + 1);

	// копируем значения в новый массив из исходного со смещением на 1 в нужном месте
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (j >= indexCol)
				buffer[i][j + 1] = arr[i][j];
			else
				buffer[i][j] = arr[i][j];
		}
	}

	// добавляем столбец в массив
	for (int i = 0; i < rows; ++i) buffer[i][indexCol] = newCol[i];

	// подставляем новый массив на место старого (обновляем ссылки)
	arr = buffer;
	cols++;
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
void erase_row(int**& arr, int& rows, int cols, int indexRowDel) // Удалает строку по заданному индексу
{
	// освобождаем память под строку, которую нужно удалить
	delete[] arr[indexRowDel];

	// создаем новый массив с количеством строк уменьшенным на 1 
	int** buffer = new int* [rows - 1];
	Allocate(buffer, rows - 1, cols);

	// копируем значения в новый массив из исходного 
	int newIndex = 0; // счётчик чтобы учесть сдвиг строк после удаления нужной
	for (int i = 0; i < rows; ++i)
	{
		if (i != indexRowDel)
		{
			for (int j = 0; j < cols; ++j) 
				buffer[newIndex][j] = arr[i][j];
			++newIndex;
		}
	}

	// обновляем ссылки на массив и количество строк
	arr = buffer;
	rows--;
}

void Allocate(int** arr, const int rows, const int cols) // Выделение памяти под двумерный динамический массив
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
}
void Clear(int** arr, const int rows, const int cols)
{
	// Удаление
	// 1. Сначала удаляем строки
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	// 2. После удаления строк, удаляем массив указателей:
	delete[] arr;
}