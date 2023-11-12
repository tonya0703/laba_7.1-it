#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** c, const int rowCount, const int colCount, const int Low, const int High);
void Sort(int** a, const int rowCount, const int colCount);
void Change(int** a, const int row1, const int row2, const int rowCount);
void Print(int** c, const int rowCount, const int colCount);
void Calc(int** c, const int rowCount, const int colCount, int& S, int& k);


int main()
{
	srand((unsigned)time(NULL));
	int Low = -21;
	int High = 24;
	int rowCount = 9;
	int colCount = 6;
	int S = 0;
	int k = 0;

	int** c = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		c[i] = new int[colCount];
	Create(c, rowCount, colCount, Low, High);
	Print(c, rowCount, colCount);
	Calc(c, rowCount, colCount, S, k);
	Print(c, rowCount, colCount);
	Sort(c, rowCount, colCount);
	Print(c, rowCount, colCount);
	cout << "Sum = " << S << endl;
	cout << "Count = " << k;

}

void Create(int** c, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			c[i][j] = Low + rand() % (High - Low + 1);
}

void Sort(int** c, const int rowCount, const int colCount)
{
	for (int i = 0; i < colCount - 1; i++)
		for (int j = 0; j < colCount - i - 1; j++)
			if ((c[0][j] < c[0][j + 1]) 
				|| 
				(c[0][j] == c[0][j + 1] && c[1][j] < c[1][j + 1]) 
				|| 
				(c[0][j] == c[0][j + 1] && c[1][j] == c[1][j + 1] && c[2][j] > c[2][j + 1]))
			{
				Change(c, j, j + 1, rowCount);
			}
	
}

void Change(int** c, const int row1, const int row2, const int rowCount)
{
	int tmp;
	for (int j = 0; j < rowCount; j++)
	{
		tmp = c[j][row1];
		c[j][row1] = c[j][row2];
		c[j][row2] = tmp;
	}

}

void Print(int** c, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << c[i][j];
		cout << endl;
	}
	cout << endl;
}

void Calc(int** c, const int rowCount, const int colCount, int& S, int& k)
{
	S = 0;
	k = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (c[i][j] > 0 && c[i][j] % 3 == 0)
			{
				S += c[i][j];
				k++;
				c[i][j] = 0;
			}
}