#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void PrintMatrixp20(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			printf("%.2i     ", Arr[i][j]);
		}
		cout << endl;
	}
}

bool IsPalindromeMatrixp20(int Arr[3][3], short Row, short Col)
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (Arr[i][j] != Arr[i][Col - j - 1])
				return false;
		}
	}
	return true;
}

void Prob20_IsPalindromeMatrix()
{
	srand((unsigned)time(0));

	int Matrix1[3][3] = { {1, 2, 1}, {2, 1, 2}, {3, 5, 3} };

	cout << "Matrix1:\n";
	PrintMatrixp20(Matrix1, 3, 3);


	if (IsPalindromeMatrixp20(Matrix1, 3, 3))
		cout << "Palimdrome!\n";
	else
		cout << "Not Palindrome!\n";
	
	
system("Pause>0");
}