## 11. AreEqualMatrices
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

bool CheckMatricesEquivilant(int Arr[3][3], int Arr2[3][3], short Row, short Col)
{
	return (SumOfMatrix(Arr, 3, 3) == SumOfMatrix(Arr2, 3, 3));
}

int main(void)
{
	srand((unsigned)time(0));

	int Matrix1[3][3], Matrix2[3][3];

	FIllMatrixWithRandomNumbers(Matrix1, 3, 3);
	FIllMatrixWithRandomNumbers(Matrix2, 3, 3);

	cout << "Matrix1:\n";
	PrintMatrix(Matrix1, 3, 3);
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix2, 3, 3);

	if (CheckMatricesEquivilant(Matrix1, Matrix2, 3, 3))
		cout << "They are equivilant!\n";
	else
		cout << "They are not equivilant!\n";

	system("Pause>0");
}
```

## 12. AreTypicalMAtrices
```C++
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

bool AreTypicalMatrices(int Arr[3][3], int Arr2[3][3], short Row, short Col)
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (Arr[i][j] != Arr2[i][j])
				return false;
		}
	}
	return true;
}

int main(void)
{
	srand((unsigned)time(0));

	int Matrix1[3][3], Matrix2[3][3];

	FIllMatrixWithRandomNumbers(Matrix1, 3, 3);
	FIllMatrixWithRandomNumbers(Matrix2, 3, 3);

	cout << "Matrix1:\n";
	PrintMatrix(Matrix1, 3, 3);
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix2, 3, 3);

	if (AreTypicalMatrices(Matrix1, Matrix2, 3, 3))
		cout << "They are Typical!\n";
	else
		cout << "They are not Typical!\n";

	system("Pause>0");
}
```

## 13. IsIdentityMatrix
### My sol
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

bool IsIdentityMatrix(int Arr[3][3], short Row, short Col)
{
	bool Diagnose = 0, Zeros = 0;

	if (Arr[0][0] == 1 && Arr[1][1] == 1 && Arr[2][2] == 1)
		Diagnose = true;
	if (Arr[0][1] == 0 && Arr[0][2] == 0 && Arr[1][0] == 0 &&
		Arr[1][2] == 0 && Arr[2][0] == 0 && Arr[2][1] == 0)
		Zeros = true;

	return (Diagnose && Zeros);
}

int main(void)
{
	srand((unsigned)time(0));

	int Matrix1[3][3] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };

	//FIllMatrixWithRandomNumbers(Matrix1, 3, 3);

	cout << "Matrix1:\n";
	PrintMatrix(Matrix1, 3, 3);


	if (IsIdentityMatrix(Matrix1, 3, 3))
		cout << "It is an identity matrix!\n";
	else
		cout << "It is not an identity matrix!\n";

	system("Pause>0");
}
```
### Had's sol
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

bool IsIdentityMatrix(int Arr[3][3], short Row, short Col)
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (i == j && Arr[i][j] != 1)
				return false;
			else if (i != j && Arr[i][j] != 0)
				return false;
		}
	}
	return true;
}

int main(void)
{
	srand((unsigned)time(0));

	int Matrix1[3][3] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };

	//FIllMatrixWithRandomNumbers(Matrix1, 3, 3);

	cout << "Matrix1:\n";
	PrintMatrix(Matrix1, 3, 3);


	if (IsIdentityMatrix(Matrix1, 3, 3))
		cout << "It is an identity matrix!\n";
	else
		cout << "It is not an identity matrix!\n";

	system("Pause>0");
}
```
## 14. 
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

bool IsScalarMatrix(int Arr[3][3], short Row, short Col)
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (i == j && Arr[i][j] != Arr[0][0])
			{
				return false;
			}
			else if (i != j && Arr[i][j] != 0)
				return false;
		}
	}
	return true;
}

int main(void)
{
	srand((unsigned)time(0));

	int Matrix1[3][3] = { {1, 0, 0}, {0, 4, 0}, {0, 0, 1} };

	//FIllMatrixWithRandomNumbers(Matrix1, 3, 3);

	cout << "Matrix1:\n";
	PrintMatrix(Matrix1, 3, 3);


	if (IsScalarMatrix(Matrix1, 3, 3))
		cout << "It is a scalar matrix!\n";
	else
		cout << "It is not a scalar matrix!\n";

	system("Pause>0");
}
```

## 15. NumberCountInMatrix
###  My sol
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

int NumberCountInMatrix(int Arr[3][3], short Row, short Col, int Number)
{
	short Counter = 0;
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (Arr[i][j] == Number)
			{
				Counter += 1;
			}
			
		}
	}
	return Counter;
}

int main(void)
{
	srand((unsigned)time(0));

	int Matrix1[3][3] = { {1, 1, 1}, {0, 4, 0}, {0, 0, 1} };

	//FIllMatrixWithRandomNumbers(Matrix1, 3, 3);

	cout << "Matrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	int Number = 0;

	cout << "\nThe Number You Want to check its count: "; cin >> Number;

	cout << "\nThe Number Count = " << NumberCountInMatrix(Matrix1, 3, 3, Number);
	

	system("Pause>0");
}
```

### His sol 
The same, But why did he put `;` after the if statement?? #question 
## 16. IsSparceMatrix
###  My sol
```c++
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

bool IsSparceMatrix(int Arr[3][3], short Row, short Col)
{
	short ZerosCounter = 0;
	short NonZerosCounter = 0;

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (Arr[i][j] == 0)
				ZerosCounter++;
			else
				NonZerosCounter++;
		}
	}
	return (ZerosCounter > NonZerosCounter);
}

int main(void)
{
	srand((unsigned)time(0));

	int Matrix1[3][3] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };

	//FIllMatrixWithRandomNumbers(Matrix1, 3, 3);

	cout << "Matrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	int Number = 0;

	if (IsSparceMatrix(Matrix1, 3, 3))
		cout << "It is a sparce matrix\n";
	else
		cout << "It is Not sparce matrix\n";
	
	system("Pause>0");
}
```

### His
- it is much better!!
```c++
int CountNumberInMatrix(int Arr[3][3], short Row, short Col, int Number)
{
	short Counter = 0;
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (Arr[i][j] == Number)
			{
				Counter += 1;
			}
		}
	}
	return Counter;
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

bool IsSparceMatrix(int Arr[3][3], short Row, short Col)
{
	int MatrixSize = Row * Col;

	return (CountNumberInMatrix(Arr, 3, 3, 0) > (MatrixSize / 2));
}

int main(void)
{
	srand((unsigned)time(0));

	int Matrix1[3][3] = { {1, 10, 10}, {0, 0, 0}, {0, 0, 1} };

	//FIllMatrixWithRandomNumbers(Matrix1, 3, 3);

	cout << "Matrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	int Number = 0;

	if (IsSparceMatrix(Matrix1, 3, 3))
		cout << "It is a sparce matrix\n";
	else
		cout << "It is Not sparce matrix\n";
	
	system("Pause>0");
}
```

## 17. FindNumberInMatrix

### MySol
```c++
bool IsNumberInMatrix(int Arr[3][3], short Row, short Col, int Number)
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (Arr[i][j] == Number)
			{
				return true;
			}
		}
	}
	return false;
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

	int Matrix1[3][3] = { {1, 10, 10}, {0, 0, 0}, {0, 8, 1} };

	//FIllMatrixWithRandomNumbers(Matrix1, 3, 3);

	cout << "Matrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	int Number = 0;

	if (IsNumberInMatrix(Matrix1, 3, 3, 8))
		cout << "It is FOUND\n";
	else
		cout << "It is NOT FOUND\n";
	
	system("Pause>0");
}
```
## 18. FindINtersectNumbers
### My Sol
```c++
#include "Basics.h"
#include <iostream>
#include <iomanip>

using namespace std;

int FindIntersectNumbersFrom2Matrices(int Arr[3][3], int Arr2[3][3], int Arr3[18], short Row, short Col)
{
	int temp = 0;
	int counter = 0;
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			temp = Arr[i][j];
			for (int k = 0; k < Row; k++)
			{
				for (int l = 0; l < Col; l++)
				{
					if (temp == Arr2[k][l])
					{
						Arr3[counter] = temp;
			            counter += 1;
					}

				}
			}

		}
	}
	return counter;
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

	int Matrix1[3][3], Matrix2[3][3];
	int Arr[10];

	FIllMatrixWithRandomNumbers(Matrix1, 3, 3);
	FIllMatrixWithRandomNumbers(Matrix2, 3, 3);

	cout << "Matrix1:\n";
	PrintMatrix(Matrix1, 3, 3);
	cout << "\nMatrix2:\n";
	PrintMatrix(Matrix2, 3, 3);

	int Number = 0;

	int size = FindIntersectNumbersFrom2Matrices(Matrix1, Matrix2, Arr, 3, 3);

	cout << "Intersected Numbers Are: \n";
	
	PrintArray(Arr, size);
	
	
	system("Pause>0");
}
```

### His Sol
```c++
void FindIntersectNumbersFrom2Matrices(int Arr[3][3], int Arr2[3][3], short Row, short Col)
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (IsNumberInMatrix(Arr2, Row, Col, Arr[i][j]))
			{
				cout << setw(2) << Arr[i][j] << "   ";
			}
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

	int Matrix1[3][3], Matrix2[3][3];
	int Arr[10];

	FIllMatrixWithRandomNumbers(Matrix1, 3, 3);
	FIllMatrixWithRandomNumbers(Matrix2, 3, 3);

	cout << "Matrix1:\n";
	PrintMatrix(Matrix1, 3, 3);
	cout << "\nMatrix2:\n";
	PrintMatrix(Matrix2, 3, 3);

	int Number = 0;

	cout << "Intersected Numbers Are: \n";
	
	FindIntersectNumbersFrom2Matrices(Matrix1, Matrix2, 3, 3);
	
	system("Pause>0");
}
```
## 19. FindMin & FindMax
```c++
int FindMaxNumberInMatrix(int Arr[3][3], short Row, short Col)
{
	int Max = Arr[0][0];

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (Arr[i][j] > Max)
			{
				Max = Arr[i][j];
			}
		}
	}
	return Max;
}

int FindMinNumberInMatrix(int Arr[3][3], short Row, short Col)
{
	int Min = Arr[0][0];

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (Arr[i][j] < Min)
			{
				Min = Arr[i][j];
			}
		}
	}
	return Min;
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


	cout << "\nMax = " << FindMaxNumberInMatrix(Matrix1, 3, 3);
	cout << "\nMin = " << FindMinNumberInMatrix(Matrix1, 3, 3);
	
	
	system("Pause>0");
}
```


## 20. IsPlindromeMatrix
```c++
int FindMaxNumberInMatrix(int Arr[3][3], short Row, short Col)
{
	int Max = Arr[0][0];

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (Arr[i][j] > Max)
			{
				Max = Arr[i][j];
			}
		}
	}
	return Max;
}


bool IsPalindromeMatrix(int Arr[3][3], short Row, short Col)
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

	int Matrix1[3][3] = { {1, 2, 1}, {2, 1, 2}, {3, 5, 3} };

	cout << "Matrix1:\n";
	PrintMatrix(Matrix1, 3, 3);


	if (IsPalindromeMatrix(Matrix1, 3, 3))
		cout << "Palimdrome!\n";
	else
		cout << "Not Palindrome!\n";
	
	
	system("Pause>0");
}
```

### A Better sol
```c++
int FindMaxNumberInMatrix(int Arr[3][3], short Row, short Col)
{
	int Max = Arr[0][0];

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (Arr[i][j] > Max)
			{
				Max = Arr[i][j];
			}
		}
	}
	return Max;
}


bool IsPalindromeMatrix(int Arr[3][3], short Row, short Col)
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col / 2; j++)
		{
			if (Arr[i][j] != Arr[i][Col - j - 1])
				return false;
		}
	}
	return true;
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

	int Matrix1[3][3] = { {1, 2, 1}, {2, 1, 2}, {3, 5, 3} };

	cout << "Matrix1:\n";
	PrintMatrix(Matrix1, 3, 3);


	if (IsPalindromeMatrix(Matrix1, 3, 3))
		cout << "Palimdrome!\n";
	else
		cout << "Not Palindrome!\n";
	
	
	system("Pause>0");
}
```