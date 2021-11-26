#include <iostream>
#include <iomanip>
#include <time.h>
#include <cmath>

using namespace std;

void CreateRow(int** mas, const int rowNo, const int N, const int Low, const int High, int colNo)
{
	mas[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < N - 1)
		CreateRow(mas, rowNo, N, Low, High, colNo + 1);
}
void CreateRows(int** mas, const int N, const int Low, const int High, int rowNo)
{
	CreateRow(mas, rowNo, N, Low, High, 0);
	if (rowNo < N - 1)
		CreateRows(mas, N, Low, High, rowNo + 1);
}
void PrintRow(int** mas, const int rowNo, const int N, int colNo)
{
	cout << setw(4) << mas[rowNo][colNo];
	if (colNo < N - 1)
		PrintRow(mas, rowNo, N, colNo + 1);
	else
		cout << endl;
}
void PrintRows(int** mas, const int N, int rowNo)
{
	PrintRow(mas, rowNo, N, 0);
	if (rowNo < N - 1)
		PrintRows(mas, N, rowNo + 1);
	else
		cout << endl;
}

int SearchMin(int** mas, const int N, int min, int j, int i)
{
	if (i < N)
	{
		if (mas[i][j] < min)
		{
			min = mas[i][j];
			SearchMin(mas, N, min, j, i + 1);
		}
		else
			SearchMin(mas, N, min, j, i + 1);
	}
	else
		return min;
}

int SearchMax(int** mas, const int N, const int k, int max, int g)
{
	if (g < N)
	{
		if (g % 2 != 0 && SearchMin(mas, N, 29, g, 0) > max)
		{
			max = SearchMin(mas, N, 29, g, 0);
			SearchMax(mas, N, k, max, g + 1);
		}
		else
			SearchMax(mas, N, k, max, g + 1);
	}
	else
		return max;
}

int main()
{
	srand((unsigned)time(NULL));
	int N, K;

	cout << "N = "; cin >> N;
	cout << "K = "; cin >> K;
	cout << endl;

	int** a = new int* [N];
	for (int i = 0; i < N; i++)
		a[i] = new int[N];

	int Low = 1;
	int	High = 28;

	CreateRows(a, N, Low, High, 0);
	PrintRows(a, N, 0);

	cout << "Max = " << SearchMax(a, N, K, 0, 0) << endl;

	return 0;
}