## 1. Random Matrix Numbers

### My sol

```c++
#include "Basics.h"
#include <iostream>

#include <iomanip>

using namespace std;

int main(void)
{
	srand((unsigned)time(NULL));

	int Rand = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Rand = RandomNumber(1, 100);
			if (Rand < 10)
				cout << " " << Rand;
			else
				cout << Rand;
			cout << "       ";
		}
		cout << endl;
	}
}
```

### His sol
```c++
void FIllMatrixWithRandomNumbers(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Arr[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMAtrix(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(3) << Arr[i][j] << "    ";
		}
		cout << endl;
	}
}

int main(void)
{
	srand((unsigned) time(0));

	int Arr[3][3];

	FIllMatrixWithRandomNumbers(Arr, 3, 3);
	PrintMAtrix(Arr, 3, 3);
}
```
#question What's `system(pause>0)` ?
## 2. Sum Matrix' Rows
### My Sol
```c++
void FIllMatrixWithRandomNumbers(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Arr[i][j] = RandomNumber(1, 100);
		}
	}
}

void SumMatrixsRows(int SummArray[3], int Arr[3][3])
{
	SummArray[0] = 0;
	SummArray[1] = 0;
	SummArray[2] = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			*(SummArray+i) += Arr[i][j];
		}
	}
}


void PrintMAtrix(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(3) << Arr[i][j] << "    ";
		}
		cout << endl;
	}
}

void PrintArray(int Arr[3])
{
	for (int i = 0; i < 3; i++)
	{
		cout << "Sum of [" << i + 1 << "] Row: ";
		cout << Arr[i] << endl;
	}
}

int main(void)
{
	srand((unsigned) time(0));

	int Arr[3][3];
	int SummRows[3];

	FIllMatrixWithRandomNumbers(Arr, 3, 3);
	SumMatrixsRows(SummRows, Arr);

	cout << "The matrix:\n";
	PrintMAtrix(Arr, 3, 3);

	cout << "Rows Summation:\n";
	PrintArray(SummRows);
}
```

### Had's sol
```c++
void FIllMatrixWithRandomNumbers(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Arr[i][j] = RandomNumber(1, 100);
		}
	}
}


void PrintMAtrix(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(3) << Arr[i][j] << "    ";
		}
		cout << endl;
	}
}

int SummRow(int Arr[3][3], short CurrentRow, short Col)
{
	int sum = 0;
	for (int i = 0; i < Col; i++)
	{
		sum += Arr[CurrentRow][i];
	}
	return sum;
}

void PrintEachRowSum(int Arr[3][3], short Row, short Col)
{
	for (short i = 0; i < Row; i++)
	{
		cout << "The sum of the " << i + 1 << " row :" << SummRow(Arr, i, 3) << endl;
	}
}

int main(void)
{
	srand((unsigned) time(0));

	int Arr[3][3];
	int SummRows[3];

	FIllMatrixWithRandomNumbers(Arr, 3, 3);
	
	PrintMAtrix(Arr, 3, 3);

	PrintEachRowSum(Arr, 3, 3);
}
```

## 3. == Using Array
### My sol
```c++
void FIllMatrixWithRandomNumbers(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Arr[i][j] = RandomNumber(1, 100);
		}
	}
}

void SumMatrixsRows(int SummArray[3], int Arr[3][3])
{
	SummArray[0] = 0;
	SummArray[1] = 0;
	SummArray[2] = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			*(SummArray+i) += Arr[i][j];
		}
	}
}


void PrintMAtrix(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(3) << Arr[i][j] << "    ";
		}
		cout << endl;
	}
}

void PrintArray(int Arr[3])
{
	for (int i = 0; i < 3; i++)
	{
		cout << "Sum of [" << i + 1 << "] Row: ";
		cout << Arr[i] << endl;
	}
}

int main(void)
{
	srand((unsigned) time(0));

	int Arr[3][3];
	int SummRows[3];

	FIllMatrixWithRandomNumbers(Arr, 3, 3);
	SumMatrixsRows(SummRows, Arr);

	cout << "The matrix:\n";
	PrintMAtrix(Arr, 3, 3);

	cout << "Rows Summation:\n";
	PrintArray(SummRows);
}
```

### His..
```c++
int SummRow(int Arr[3][3], short CurrentRow, short Col)
{
	int sum = 0;
	for (int i = 0; i < Col; i++)
	{
		sum += Arr[CurrentRow][i];
	}
	return sum;
}

void FIllMatrixWithRandomNumbers(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Arr[i][j] = RandomNumber(1, 100);
		}
	}
}

void SumMatrixsRows(int SummArray[3], int Arr[3][3], short Row, short Col)
{
	for (int i = 0; i < Row; i++)
	{
		*(SummArray + i) = SummRow(Arr, i, 3);
	}
}


void PrintMAtrix(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(3) << Arr[i][j] << "    ";
		}
		cout << endl;
	}
}

void PrintRowsSumaArray(int Arr[3])
{
	for (int i = 0; i < 3; i++)
	{
		cout << "Sum of [" << i + 1 << "] Row: ";
		cout << Arr[i] << endl;
	}
}

int main(void)
{
	srand((unsigned)time(0));

	int Arr[3][3];
	int SummRows[3];

	FIllMatrixWithRandomNumbers(Arr, 3, 3);

	cout << "The matrix:\n";
	PrintMAtrix(Arr, 3, 3);

	SumMatrixsRows(SummRows, Arr, 3, 3);

	cout << "Rows Summation:\n";
	PrintRowsSumaArray(SummRows);

	system("Pause>0");
}
```

## 4. Sum each Column in A matrix & 5.
### My sol
```c++
using namespace std;

int SummColumn(int Arr[3][3], short Row, short CurrentCol)
{
	int sum = 0;
	for (int i = 0; i < Row; i++)
	{
		sum += Arr[i][CurrentCol];
	}
	return sum;
}

void FIllMatrixWithRandomNumbers(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Arr[i][j] = RandomNumber(1, 100);
		}
	}
}

void SumMatrixsColumns(int SummArray[3], int Arr[3][3], short Row, short Col)
{
	for (int i = 0; i < Col; i++)
	{
		*(SummArray + i) = SummColumn(Arr, Row, i);
	}
}


void PrintMAtrix(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(3) << Arr[i][j] << "    ";
		}
		cout << endl;
	}
}

void PrintColumnSumaArray(int Arr[3])
{
	for (int i = 0; i < 3; i++)
	{
		cout << "Sum of [" << i + 1 << "] Column: ";
		cout << Arr[i] << endl;
	}
}

int main(void)
{
	srand((unsigned)time(0));

	int Arr[3][3];
	int SummRows[3];

	FIllMatrixWithRandomNumbers(Arr, 3, 3);

	cout << "The matrix:\n";
	PrintMAtrix(Arr, 3, 3);

	SumMatrixsColumns(SummRows, Arr, 3, 3);

	cout << "Column Summation:\n";
	PrintColumnSumaArray(SummRows);

	system("Pause>0");
}
```

## 6. Fill Matrix with ordered Numbers
```c++
void FIllMatrixWithOrderedNumbers(int Arr[3][3], short Rows, short Cols)
{
	int Summ = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Summ++;
			Arr[i][j] = Summ;
		}
	}
}

void PrintMAtrix(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(3) << Arr[i][j] << "    ";
		}
		cout << endl;
	}
}

int main(void)
{
	srand((unsigned)time(0));

	int Arr[3][3];
	int SummRows[3];

	FIllMatrixWithOrderedNumbers(Arr, 3, 3);

	cout << "The matrix:\n";
	PrintMAtrix(Arr, 3, 3);

	system("Pause>0");
}
```

## 7. Transpose Matrix
```c++
void FIllMatrixWithOrderedNumbers(int Arr[3][3], short Rows, short Cols)
{
	int Summ = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Summ++;
			Arr[i][j] = Summ;
		}
	}
}

void PrintTranspodeMatrix(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(3) << Arr[j][i] << "    ";
		}
		cout << endl;
	}
}

int main(void)
{
	srand((unsigned)time(0));

	int Arr[3][3];
	int SummRows[3];

	FIllMatrixWithOrderedNumbers(Arr, 3, 3);

	cout << "The matrix:\n";
	PrintTranspodeMatrix(Arr, 3, 3);

	system("Pause>0");
}
```

### His sol
```c++
void FIllMatrixWithOrderedNumbers(int Arr[3][3], short Rows, short Cols)
{
	int Summ = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Summ++;
			Arr[i][j] = Summ;
		}
	}
}

void TransposeMatrix(int Arr[3][3], int TransposeArr[3][3], short Row, short Column)
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
		{
			TransposeArr[i][j] = Arr[j][i];
		}
		cout << endl;
	}
}

void PrintMatrix(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(3) << Arr[i][j] << "    ";
		}
		cout << endl;
	}
}

int main(void)
{
	srand((unsigned)time(0));

	int Arr[3][3];
	int TransposeArray[3][3];

	FIllMatrixWithOrderedNumbers(Arr, 3, 3);

	cout << "The matrix:\n";
	PrintMatrix(Arr, 3, 3);

	TransposeMatrix(Arr, TransposeArray, 3, 3);

	cout << "The Transpode matrix:\n";
	PrintMatrix(TransposeArray, 3, 3);

	system("Pause>0");
}
```

## 8. Multiply 2 Matrices
```c++
void FIllMatrixWithRandomNumbers(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void Multiply2Matrix(int Matrix1[3][3], int Matrix2[3][3], short Row, short Column)
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
		{
			Matrix2[i][j] *= Matrix1[i][j];
		}
	}
}

void PrintMatrix(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			printf("%.2i     ",Arr[i][j]);  
		}
		cout << endl;
	}
}

int main(void)
{
	srand((unsigned)time(0));

	int Matrix1[3][3];
	int Matrix2[3][3];

	FIllMatrixWithRandomNumbers(Matrix1, 3, 3);
	FIllMatrixWithRandomNumbers(Matrix2, 3, 3);

	cout << "Matrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nMatrix2:\n";
	PrintMatrix(Matrix2, 3, 3);

	Multiply2Matrix(Matrix1, Matrix2, 3, 3);

	cout << "\nMatrix2 Multiplied by Matrix1:\n";
	PrintMatrix(Matrix2, 3, 3);

	system("Pause>0");
}
```

### His sol
```c++
void FIllMatrixWithRandomNumbers(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void Multiply2Matrix(int Matrix1[3][3], int Matrix2[3][3], int MatrixResult[3][3], short Row, short Column)
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
		{
			MatrixResult[i][j] = Matrix2[i][j] * Matrix1[i][j];
		}
	}
}

void PrintMatrix(int Arr[3][3], short Rows, short Cols)
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

int main(void)
{
	srand((unsigned)time(0));

	int Matrix1[3][3], Matrix2[3][3], MatrixResult[3][3];

	FIllMatrixWithRandomNumbers(Matrix1, 3, 3);
	FIllMatrixWithRandomNumbers(Matrix2, 3, 3);

	cout << "Matrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nMatrix2:\n";
	PrintMatrix(Matrix2, 3, 3);

	Multiply2Matrix(Matrix1, Matrix2, MatrixResult, 3, 3);

	cout << "\nMatrix2 Multiplied by Matrix1:\n";
	PrintMatrix(MatrixResult, 3, 3);

	system("Pause>0");
}
```

## 9. Print Middle Row & Column 
```c++
void FIllMatrixWithRandomNumbers(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows + 1; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintMiddleRowOfMatrix(int Matrix1[3][3], short Row, short Column)
{
	int MiddleRow = Row / 2;

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
		{
			if (i == MiddleRow)
			{
				printf("%.2i     ", Matrix1[i][j]);
			}
		}
		cout << endl;
	}
}

void PrintMiddleColumnOfMatrix(int Matrix1[3][3], short Row, short Column)
{
	int MiddleColumn = Column/ 2;

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
		{
			if (j == MiddleColumn)
			{
				printf("%.2i     ", Matrix1[i][j]);
			}
		}
		cout << endl;
	}
}



void PrintMatrix(int Arr[3][3], short Rows, short Cols)
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

int main(void)
{
	srand((unsigned)time(0));

	int Matrix1[3][3];

	FIllMatrixWithRandomNumbers(Matrix1, 3, 3);

	cout << "Matrix1:\n";
	PrintMatrix(Matrix1, 3, 3);
	

	cout << "\nRows:\n";
	PrintMiddleRowOfMatrix(Matrix1, 3, 3);

	cout << "\nColumns:\n";
	PrintMiddleColumnOfMatrix(Matrix1, 3, 3);
	system("Pause>0");
}
```

### His Sol
```c++
void FIllMatrixWithRandomNumbers(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows + 1; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintMiddleRowOfMatrix(int Matrix1[3][3], short Row, short Column)
{
	int MiddleRow = Row / 2;

	for (int i = 0; i < Row; i++)
	{
		printf("%.2i     ", Matrix1[MiddleRow][i]);
	}
	cout << endl;
}

void PrintMiddleColumnOfMatrix(int Matrix1[3][3], short Row, short Column)
{
	int MiddleColumn = Column/ 2;

	for (int i = 0; i < Row; i++)
	{
		printf("%.2i     ", Matrix1[i][MiddleColumn]);
		cout << endl;
	}
}



void PrintMatrix(int Arr[3][3], short Rows, short Cols)
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

int main(void)
{
	srand((unsigned)time(0));

	int Matrix1[3][3];

	FIllMatrixWithRandomNumbers(Matrix1, 3, 3);

	cout << "Matrix1:\n";
	PrintMatrix(Matrix1, 3, 3);
	

	cout << "\nRows:\n";
	PrintMiddleRowOfMatrix(Matrix1, 3, 3);

	cout << "\nColumns:\n";
	PrintMiddleColumnOfMatrix(Matrix1, 3, 3);
	system("Pause>0");
}
```

## 10. Sum of Matrix
```c++
void FIllMatrixWithRandomNumbers(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows + 1; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Arr[i][j] = RandomNumber(1, 10);
		}
	}
}

int SumOfMatrix(int Arr[3][3], short Row, short Column)
{
	int Sum = 0;
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column ; j++)
		{
			Sum += Arr[i][j];
		}
		cout << endl;
	}
	return Sum;
}

void PrintMatrix(int Arr[3][3], short Rows, short Cols)
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

int main(void)
{
	srand((unsigned)time(0));

	int Matrix1[3][3];

	FIllMatrixWithRandomNumbers(Matrix1, 3, 3);

	cout << "Matrix:\n";
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nSum of Matrix = " << SumOfMatrix(Matrix1, 3, 3);
	
	system("Pause>0");
}
```

