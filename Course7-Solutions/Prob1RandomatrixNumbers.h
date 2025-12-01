#pragma once
#include <iostream>
#include "RandomNumber.h"

using namespace std;

void GenerateRandomNumberMatrix(int Matrix[3][3], int from, int to)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Matrix[i][j] = RandomNumber(from, to);
		}
	}
}

void PrintMatrix(int matrix[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << matrix[i][j];
			cout << "  ";
		}
		cout << endl;
	}
}

void RandomNumberMatrix()
{
	int array[3][3];
	GenerateRandomNumberMatrix(array, 10, 100);

	PrintMatrix(array);
}