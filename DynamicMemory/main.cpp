#include<iostream>
using namespace std;
using::std::cin;
using::std::cout;
using::std::endl;

#define tab "\t"
//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

int** Allocate(const int rows, const int cols);
void Clear(int** arr, const int rows);

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, int value);
int** push_row_back(int** arr, int& rows, const int cols);
void push_col_back(int** arr, const int rows, int& cols);
int* push_front(int arr[], int& n, int value);
int** push_row_front(int** arr, int& rows, const int cols);
void push_col_front(int** arr, const int rows, int& cols);

int* pop_back(int arr[], int& n);
int** pop_row_back(int** arr, int& rows, int cols);
void pop_col_back(int** arr, const int rows, int& cols);
int* pop_front(int arr[], int& n);
int** pop_row_front(int** arr, int& rows, const int cols);
void pop_col_front(int** arr, const int rows, int& cols);

void insert(int arr[], const int n, int index, int value);
int** insert_row(int** arr, int& rows, const int cols, int indexRow);
void insert_col(int** arr, const int rows, int& cols, int indexCol);

int* erase(int arr[], int& n, int index);
int** erase_row(int** arr, int& rows, const int cols, int indexRowDel);
void erase_col(int** arr, const int rows, int& cols, int indexColDel);


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

	int** arr = Allocate(rows, cols);

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Массив с добавленной в конец новой строкой: " << endl;
	arr = push_row_back(arr, rows, cols);
	//FillRand(arr[rows - 1], cols, 100, 1000);
	Print(arr, rows, cols);

	cout << "Массив +1 строка в начало: " << endl;
	arr = push_row_front(arr, rows, cols);
	//FillRand(arr[0], cols, 100, 1000);
	Print(arr, rows, cols);

	cout << "Массив без последней строки: " << endl;
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Массив без первой строки: " << endl;
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Массив +1 стоблец в конец: " << endl;
	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Массив +1 стоблец в начало: " << endl;
	push_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Массив -1 стоблец в конце: " << endl;
	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Массив -1 стоблец в начале: " << endl;
	pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	int indexRow;
	do
	{
		cout << "Введите индекс строки, куда хотите вставить новую строку: "; cin >> indexRow;
		if (indexRow > rows) cout << "Индекс не может быть больше, чем всего строк в массиве!" << endl;
	} while (indexRow > rows);
	arr = insert_row(arr, rows, cols, indexRow);
	Print(arr, rows, cols);

	do
	{
		cout << "Введите индекс строки, которую хотите удалить: "; cin >> indexRow;
		if (indexRow > rows) cout << "Индекс не может быть больше, чем всего строк в массиве!" << endl;
	} while (indexRow > rows);
	arr = erase_row(arr, rows, cols, indexRow);
	Print(arr, rows, cols);

	int indexCol;
	do
	{
		cout << "Введите индекс столбца (элемента строки), куда хотите вставить новый столбец: "; cin >> indexCol;
		if (indexCol > cols) cout << "Индекс не может быть больше, чем всего столбцов в массиве!" << endl;
	} while (indexCol > cols);
	insert_col(arr, rows, cols, indexCol);
	Print(arr, rows, cols);

	do
	{
		cout << "Введите индекс столбца, который хотите удалить: "; cin >> indexCol;
		if (indexCol > cols) cout << "Индекс не может быть больше, чем всего столбцов в массиве!" << endl;
	} while (indexCol > cols);
	erase_col(arr, rows, cols, indexCol);
	Print(arr, rows, cols);

	Clear(arr, rows);
	
#endif // DYNAMIC_MEMORY_2
}

int** Allocate(const int rows, const int cols) // Выделение памяти под двумерный динамический массив
{
	// 1. Создаем (объявляем) массив указателей
	int** arr = new int* [rows];
	// 2. Выделяем память под строки
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	return arr; // Возвращает адрес выделенной памяти, а на месте вызова она используется
}
void Clear(int** arr, const int rows)
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

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand;
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
	for (int i = 0; i < n; i++)buffer[i] = arr[i];

	// 3. Delete source array
	delete[] arr;

	// 4. Replace the address of the source array with the address of the new array
	arr = buffer;

	// 5. Only after that, there was free space at the end of the array for the new value
	arr[n] = value;
	n++;

	return arr;
}
int** push_row_back(int** arr, int& rows, const int cols)	// Добавляет строку в конец массива
{
	// 1. создаем буферный массив указателей нужного размера:
	int** buffer = new int* [rows + 1];

	// 2. копируем строки из исходного массива в массив указателей:
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];

	// 3. удаляем исходный массив указателей:
	delete[] arr;

	// 4. создаем строку и добавляем её в массив:
	buffer[rows] = new int[cols] {};

	// 5. после добавления строки в массив, кол-во его строк увеличивается
	rows++;

	return buffer;
}
void push_col_back(int** arr, const int rows, int& cols)	// Добавляет столбец в конец массива
{
	for (int i = 0; i < rows; ++i) 
	{
		int* newRow = new int[cols + 1] {}; // Выделяем память под новую строку
		for (int j = 0; j < cols; ++j) newRow[j] = arr[i][j]; // Копируем старые элементы
		delete[] arr[i]; // Освобождаем память под старую строку
		arr[i] = newRow; // Обновляем указатель на строку
	}
	cols++; // Увеличиваем количество столбцов
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
int** push_row_front(int** arr, int& rows, const int cols)	// Добавляет строку в начало массива
{
	// 1. создаем буферный массив указателей нужного размера:
	int** buffer = new int* [rows + 1];

	// 2. копируем строки из исходного массива в массив указателей:
	for (int i = 0; i < rows; i++) buffer[i + 1] = arr[i];

	// 3. удаляем исходный массив указателей:
	delete[] arr;

	// 4. создаем строку и добавляем её в массив:
	buffer[0] = new int[cols] {};

	// 5. после добавления строки в массив, кол-во его строк увеличивается
	rows++;

	return buffer;
}
void push_col_front(int** arr, const int rows, int& cols)	// Добавляет столбец в начало массива
{
	for (int i = 0; i < rows; ++i)
	{
		int* newRow = new int[cols + 1] {}; // Выделяем память под новую строку
		for (int j = 1; j < cols + 1; ++j) newRow[j] = arr[i][j - 1]; // Копируем старые элементы
		delete[] arr[i]; // Освобождаем память под старую строку
		arr[i] = newRow; // Обновляем указатель на строку
	}
	cols++; // Увеличиваем количество столбцов
}

int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
int** pop_row_back(int** arr, int& rows, const int cols) // Удаляет последнюю строку из массива
{
	// Переопределяем массив указателей
	// все указатели на строки копируются в новый массив, старый удаляем
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];
	
	delete[] arr[rows]; // !! удаляем удаляемую строку из памяти !!
	delete[] arr;
	return buffer;
}
void pop_col_back(int** arr, const int rows, int& cols)		// Удаляет последний столбец из массива
{
	for (int i = 0; i < rows; ++i)
	{
		int* newRow = new int[cols - 1]; // Выделяем память под новую строку
		for (int j = 0; j < cols - 1; ++j) newRow[j] = arr[i][j]; // Копируем старые элементы
		delete[] arr[i]; // Освобождаем память под старую строку
		arr[i] = newRow; // Обновляем указатель на строку
	}
	cols--; 
}
int* pop_front(int arr[], int& n) 
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
int** pop_row_front(int** arr, int& rows, const int cols) // Удаляет нулевую строку из массива
{
	int** buffer = new int* [rows--];

	for (int i = 0; i < rows; ++i) buffer[i] = arr[i + 1];

	delete[] arr[0];  // !! удаляем удаляемую строку из памяти !!
	delete[] arr;

	return buffer;
}
void pop_col_front(int** arr, const int rows, int& cols)	// Удаляет нулевой столбец из массива
{
	for (int i = 0; i < rows; ++i)
	{
		int* newRow = new int[cols - 1]; // Выделяем память под новую строку
		for (int j = 1; j < cols; ++j) newRow[j - 1] = arr[i][j]; // Копируем старые элементы
		delete[] arr[i]; // Освобождаем память под старую строку
		arr[i] = newRow; // Обновляем указатель на строку
	}
	cols--;
}

void insert(int arr[], const int n, int index, int value)
{
	for (int i = 0; i < n; i++) 
		if (i == index) arr[i] = value;
}
int** insert_row(int** arr, int& rows, const int cols, int indexRow)	// Вставляет строку в массив по указанному индексу
{
	int** buffer = new int* [rows + 1];

	for (int i = 0; i < rows + 1; i++) 
	{
		if (i < indexRow)
			buffer[i] = arr[i];
		else if (i == indexRow)
			buffer[i] = new int[cols] {}; // Создаем новую строку
		else 
			buffer[i] = arr[i - 1];
	}
	delete[] arr;
	rows++;

	return buffer;
}
void insert_col(int** arr, const int rows, int& cols, int indexCol)		// Вставляет столбец в массив по указанному индексу
{
	/*// генерируем добавляемый столбец
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
	cols++;*/

	for (int i = 0; i < rows; ++i)
	{
		int* newRow = new int[cols + 1] {}; // Выделяем память под новую строку
		for (int j = 0; j < cols + 1; ++j)
		{
			if (j < indexCol)
				newRow[j] = arr[i][j];
			else if (j == indexCol)
				newRow[j] = 0; // Создаем новую строку
			else
				newRow[j] = arr[i][j - 1];
		}
		delete[] arr[i]; // Освобождаем память под старую строку
		arr[i] = newRow; // Обновляем указатель на строку
	}
	cols++; // Увеличиваем количество столбцов
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
int** erase_row(int** arr, int& rows, const int cols, int indexRowDel)	// Удалает строку по заданному индексу
{
	// освобождаем память под строку, которую нужно удалить
	delete[] arr[indexRowDel];

	// создаем новый массив с количеством строк уменьшенным на 1 
	int** buffer = new int* [rows - 1];

	// копируем значения в новый массив из исходного 
	for (int i = 0; i < rows; ++i)
	{
		if (i < indexRowDel)
			buffer[i] = arr[i];
		else if (i > indexRowDel)
			buffer[i - 1] = arr[i];
	}
	delete[] arr;
	rows--;

	return buffer;
}
void erase_col(int** arr, const int rows, int& cols, int indexColDel)		// Удаляет столбец из массива по указанному индексу
{
	for (int i = 0; i < rows; ++i)
	{
		int* newRow = new int[cols - 1]; // Выделяем память под новую строку
		for (int j = 0; j < cols - 1; ++j)
		{
			if (j < indexColDel)
				newRow[j] = arr[i][j];
			else if (j >= indexColDel)
				newRow[j] = arr[i][j + 1];
		}
		delete[] arr[i]; // Освобождаем память под старую строку
		arr[i] = newRow; // Обновляем указатель на строку
	}
	cols--;
}
