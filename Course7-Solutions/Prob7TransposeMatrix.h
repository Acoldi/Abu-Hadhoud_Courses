#pragma once
#include <iostream>
#include "Prob1RandomatrixNumbers.h"


void OrderedMatrix(int matrix[3][3])
{
	int counter = 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix[i][j] = counter++;
		}
	}
}

void copyArray(int destArray[3][3], int SourceArray[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			destArray[i][j] = SourceArray[i][j];
		}
	}
}

void TransposeMatrix(int matrix[3][3])
{
	int tempMatrix[3][3];

	copyArray(tempMatrix, matrix);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tempMatrix[j][i] = matrix[i][j];
		}
	}

	copyArray(matrix, tempMatrix);
}

void ShowTransposeMatrixProb()
{
	int array[3][3];
	OrderedMatrix(array);

	PrintMatrix(array);

	cout << endl << endl;

	TransposeMatrix(array);

	PrintMatrix(array);
}