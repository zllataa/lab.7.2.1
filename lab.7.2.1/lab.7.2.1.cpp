// Lab_7_2_1.cpp
// < прізвище, ім’я автора >
// Лабораторна робота No 7.2.1)
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 0

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
int MinMax(int** a, const int rowCount, const int colCount);

int main()
{
	srand((unsigned)time(NULL));
	int Low = 7;
	int High = 65;
	int rowCount;
	int colCount;
	cout << "rowCount: "; cin >> rowCount;
	cout << "colCount: "; cin >> colCount;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);
	int minMax = MinMax(a, rowCount, colCount);
	cout << "minMax= " << minMax << endl;

}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

int MinMax(int** a, const int rowCount, const int colCount)
{
	int* max = new int[rowCount];
	for (int i = 0; i < rowCount; i++)
	{
		max[i] = a[i][0];
		for (int j = 1; j < colCount; j++)
			if (a[i][j] > max[i])
				max[i] = a[i][j];
	}
	int min = max[0];
	for (int i = 1; i < rowCount; i++)
		if (max[i] < min)
			min = max[i];
	delete[] max;
	return min;
}