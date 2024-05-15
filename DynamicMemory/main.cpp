#include<iostream>
using namespace std;
using::std::cin;
using::std::cout;
using::std::endl;

#define tab "\t"
#define DYNAMIC_MEMORY_1
//#define DYNAMIC_MEMORY_2

template<typename T>T** Allocate(const int rows, const int cols);
template<typename T>void Clear(T** arr, const int rows);

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols);
void FillRand(double** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);

template<typename T>void Print(T arr[], const int n);
template<typename T>void Print(T** arr, const int rows, const int cols);

template<typename T>T* push_back(T arr[], int& n, T value);
template<typename T>T** push_row_back(T** arr, int& rows, const int cols);
template<typename T>void push_col_back(T** arr, const int rows, int& cols);
template<typename T>T* push_front(T arr[], int& n, T value);
template<typename T>T** push_row_front(T** arr, int& rows, const int cols);
template<typename T>void push_col_front(T** arr, const int rows, int& cols);

template<typename T>T* pop_back(T arr[], int& n);
template<typename T>T** pop_row_back(T** arr, int& rows, int cols);
template<typename T>void pop_col_back(T** arr, const int rows, int& cols);
template<typename T>T* pop_front(T arr[], int& n);
template<typename T>T** pop_row_front(T** arr, int& rows, const int cols);
template<typename T>void pop_col_front(T** arr, const int rows, int& cols);

template<typename T>void insert(T arr[], const int n, int index, T value);
template<typename T>T** insert_row(T** arr, int& rows, const int cols, int indexRow);
template<typename T>void insert_col(T** arr, const int rows, int& cols, int indexCol);

template<typename T>T* erase(T arr[], int& n, int index);
template<typename T>T** erase_row(T** arr, int& rows, const int cols, int indexRowDel);
template<typename T>void erase_col(T** arr, const int rows, int& cols, int indexColDel);


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

	//int* arr = new int[n];
	double* arr = new double[n];

	FillRand(arr, n);
	Print(arr, n);

	//int value;
	double value;
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

	// тип <int> при вызове функции для явного указания компилятору 
	// (чтобы он не столкнулся с проблемой вывода типа (type deduction)), 
	// какой тип данных использовать при создании массива
	int** arr = Allocate<int>(rows, cols);

	//double** arr = Allocate<double>(rows, cols);

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

template<typename T>T** Allocate(const int rows, const int cols) // Выделение памяти под двумерный динамический массив
{
	// 1. Создаем (объявляем) массив указателей
	T** arr = new T* [rows];
	// 2. Выделяем память под строки
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols] {};
	}
	return arr; // Возвращает адрес выделенной памяти, а на месте вызова она используется
}
template<typename T>void Clear(T** arr, const int rows)
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
void FillRand(double arr[], const int n, int minRand, int maxRand)
{
	if (maxRand < minRand)
	{
		int buffer = minRand;
		minRand = maxRand;
		maxRand = buffer;
	}
	//Заполнение массива случайными числами:
	minRand *= 100;
	maxRand *= 100;
	
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand;
		*(arr + i) /= 100;
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
void FillRand(double** arr, const int rows, const int cols, int minRand, int maxRand)
{
	if (maxRand < minRand)
	{
		int buffer = minRand;
		minRand = maxRand;
		maxRand = buffer;
	}
	//Заполнение массива случайными числами:
	minRand *= 100;
	maxRand *= 100;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = minRand + rand() % (maxRand - minRand);
			//arr[i][j] = minRand + rand() % 21 - 10.5;
			arr[i][j] /= 100;
		}
	}
}

template<typename T>void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
template<typename T>void Print(T** arr, const int rows, const int cols)
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

template<typename T>T* push_back(T arr[], int& n, T value)
{
	// 1. Create buffer array
	T* buffer = new T[n + 1];

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
template<typename T>T** push_row_back(T** arr, int& rows, const int cols)	// Добавляет строку в конец массива
{
	// 1. создаем буферный массив указателей нужного размера:
	T** buffer = new T* [rows + 1];

	// 2. копируем строки из исходного массива в массив указателей:
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];

	// 3. удаляем исходный массив указателей:
	delete[] arr;

	// 4. создаем строку и добавляем её в массив:
	buffer[rows] = new T[cols] {};

	// 5. после добавления строки в массив, кол-во его строк увеличивается
	rows++;

	return buffer;
}
template<typename T>void push_col_back(T** arr, const int rows, int& cols)	// Добавляет столбец в конец массива
{
	for (int i = 0; i < rows; ++i) 
	{
		T* newRow = new T[cols + 1] {}; // Выделяем память под новую строку
		for (int j = 0; j < cols; ++j) newRow[j] = arr[i][j]; // Копируем старые элементы
		delete[] arr[i]; // Освобождаем память под старую строку
		arr[i] = newRow; // Обновляем указатель на строку
	}
	cols++; // Увеличиваем количество столбцов
}
template<typename T>T* push_front(T arr[], int& n, T value)
{
	T* buffer = new T[n + 1];

	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;

	buffer[0] = value;
	n++;

	return buffer;
}
template<typename T>T** push_row_front(T** arr, int& rows, const int cols)	// Добавляет строку в начало массива
{
	// 1. создаем буферный массив указателей нужного размера:
	T** buffer = new T* [rows + 1];

	// 2. копируем строки из исходного массива в массив указателей:
	for (int i = 0; i < rows; i++) buffer[i + 1] = arr[i];

	// 3. удаляем исходный массив указателей:
	delete[] arr;

	// 4. создаем строку и добавляем её в массив:
	buffer[0] = new T[cols] {};

	// 5. после добавления строки в массив, кол-во его строк увеличивается
	rows++;

	return buffer;
}
template<typename T>void push_col_front(T** arr, const int rows, int& cols)	// Добавляет столбец в начало массива
{
	for (int i = 0; i < rows; ++i)
	{
		T* newRow = new T[cols + 1] {}; // Выделяем память под новую строку
		for (int j = 1; j < cols + 1; ++j) newRow[j] = arr[i][j - 1]; // Копируем старые элементы
		delete[] arr[i]; // Освобождаем память под старую строку
		arr[i] = newRow; // Обновляем указатель на строку
	}
	cols++; // Увеличиваем количество столбцов
}

template<typename T>T* pop_back(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
template<typename T>T** pop_row_back(T** arr, int& rows, const int cols) // Удаляет последнюю строку из массива
{
	// Переопределяем массив указателей
	// все указатели на строки копируются в новый массив, старый удаляем
	T** buffer = new T* [--rows];
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];
	
	delete[] arr[rows]; // !! удаляем удаляемую строку из памяти !!
	delete[] arr;
	return buffer;
}
template<typename T>void pop_col_back(T** arr, const int rows, int& cols)		// Удаляет последний столбец из массива
{
	for (int i = 0; i < rows; ++i)
	{
		T* newRow = new T[cols - 1]; // Выделяем память под новую строку
		for (int j = 0; j < cols - 1; ++j) newRow[j] = arr[i][j]; // Копируем старые элементы
		delete[] arr[i]; // Освобождаем память под старую строку
		arr[i] = newRow; // Обновляем указатель на строку
	}
	cols--; 
}
template<typename T>T* pop_front(T arr[], int& n) 
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
template<typename T>T** pop_row_front(T** arr, int& rows, const int cols) // Удаляет нулевую строку из массива
{
	T** buffer = new T* [--rows];

	for (int i = 0; i < rows; ++i) buffer[i] = arr[i + 1];

	delete[] arr[0];  // !! удаляем удаляемую строку из памяти !!
	delete[] arr;

	return buffer;
}
template<typename T>void pop_col_front(T** arr, const int rows, int& cols)	// Удаляет нулевой столбец из массива
{
	for (int i = 0; i < rows; ++i)
	{
		T* newRow = new T[cols - 1]; // Выделяем память под новую строку
		for (int j = 1; j < cols; ++j) newRow[j - 1] = arr[i][j]; // Копируем старые элементы
		delete[] arr[i]; // Освобождаем память под старую строку
		arr[i] = newRow; // Обновляем указатель на строку
	}
	cols--;
}

template<typename T>void insert(T arr[], const int n, int index, T value)
{
	for (int i = 0; i < n; i++) 
		if (i == index) arr[i] = value;
}
template<typename T>T** insert_row(T** arr, int& rows, const int cols, int indexRow)	// Вставляет строку в массив по указанному индексу
{
	T** buffer = new T* [rows + 1];

	for (int i = 0; i < rows + 1; i++) 
	{
		if (i < indexRow)
			buffer[i] = arr[i];
		else if (i == indexRow)
			buffer[i] = new T[cols] {}; // Создаем новую строку
		else 
			buffer[i] = arr[i - 1];
	}
	delete[] arr;
	rows++;

	return buffer;
}
template<typename T>void insert_col(T** arr, const int rows, int& cols, int indexCol)		// Вставляет столбец в массив по указанному индексу
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
		T* newRow = new T[cols + 1] {}; // Выделяем память под новую строку
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

template<typename T>T* erase(T arr[], int& n, int index)
{
	T* buffer = new T[n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	for (int i = index; i < n; i++) buffer[i] = buffer[i + 1];
	n--;
	delete[] arr;
	return buffer;
}
template<typename T>T** erase_row(T** arr, int& rows, const int cols, int indexRowDel)	// Удалает строку по заданному индексу
{
	// освобождаем память под строку, которую нужно удалить
	delete[] arr[indexRowDel];

	// создаем новый массив с количеством строк уменьшенным на 1 
	T** buffer = new T* [rows - 1];

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
template<typename T>void erase_col(T** arr, const int rows, int& cols, int indexColDel)		// Удаляет столбец из массива по указанному индексу
{
	for (int i = 0; i < rows; ++i)
	{
		T* newRow = new T[cols - 1]; // Выделяем память под новую строку
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
