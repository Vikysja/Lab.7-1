// lab7.1(1,2).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Lab_7_1.cpp
// Квецко вікторія
// Лабораторна робота № 7.1.
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 36
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** matrix, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** matrix, const int rowCount, const int colCount);
void Sort(int** matrix, const int rowCount, const int colCount);
void Change(int** matrix, const int row1, const int row2, const int colCount);
void Calc(int** matrix, const int rowCount, const int colCount, int& Sum, int& Count);

int main()
{
	srand((unsigned)time(NULL));
	//srand(2); // for test

	const int Low = -21;
	const int High = 24;

	const int rowCount = 9;
	const int colCount = 6;

	int** matrix = new int* [rowCount];

	for (int row = 0; row < rowCount; row++)
		matrix[row] = new int[colCount];

	Create(matrix, rowCount, colCount, Low, High);
	Print(matrix, rowCount, colCount);
	Sort(matrix, rowCount, colCount);
	Print(matrix, rowCount, colCount);

	int Sum = 0;
	int Count = 0;

	Calc(matrix, rowCount, colCount, Sum, Count);

	cout << "Sum = " << Sum << endl;
	cout << "Count = " << Count << endl;

	Print(matrix, rowCount, colCount);

	for (int row = 0; row < rowCount; row++)
		delete[] matrix[row];

	delete[] matrix;

	return 0;
}

void Create(int** matrix, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int row = 0; row < rowCount; row++)
		for (int column = 0; column < colCount; column++)
			matrix[row][column] = Low + rand() % (High - Low + 1);
}

void Print(int** matrix, const int rowCount, const int colCount)
{
	cout << endl;
	for (int row = 0; row < rowCount; row++)
	{
		for (int column = 0; column < colCount; column++)
			cout << setw(4) << matrix[row][column];
		cout << endl;
	}
	cout << endl;
}

void Sort(int** matrix, const int rowCount, const int colCount)
{
	for (int i0 = 0; i0 < colCount - 1; i0++)
		for (int i1 = 0; i1 < colCount - i0 - 1; i1++) {
			if ((matrix[0][i1] > matrix[0][i1 + 1])
				||
				(matrix[0][i1] == matrix[0][i1 + 1] &&
					matrix[1][i1] > matrix[1][i1 + 1])
				||
				(matrix[0][i1] == matrix[0][i1 + 1] &&
					matrix[1][i1] == matrix[1][i1 + 1] &&
					matrix[2][i1] < matrix[2][i1 + 1]))
				Change(matrix, i1, i1 + 1, rowCount);
		}
}

void Change(int** matrix, const int col1, const int col2, const int rowCount)
{
	int temp;
	for (int j = 0; j < rowCount; j++)
	{
		temp = matrix[j][col1];
		matrix[j][col1] = matrix[j][col2];
		matrix[j][col2] = temp;
	}
}

void Calc(int** matrix, const int rowCount, const int colCount, int& Sum, int& Count)
{
	for (int row = 0; row < rowCount; row++)
		for (int column = 0; column < colCount; column++)
			if (matrix[row][column] % 3 == 0 && matrix[row][column] > 0)
			{
				Sum += matrix[row][column];
				Count++;
				matrix[row][column] = 0;
			}
}