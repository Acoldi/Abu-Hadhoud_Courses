#include <iostream>
#include <string.h>

using namespace std;

void PrintHorizentalLine(int Length)
{
    for (int i = 0; i < Length; i++)
    {
        cout << "_";
    }
    cout << '\n';
}

void PrintTableHeader()
{
    cout << "\n\n\t\t\t\tMultiplication Table From 1 to 10\n\n\t";
    for (int i = 1; i <= 10; i++)
    {
        cout << i << "\t";
    }
    cout << '\n';
    PrintHorizentalLine(83);
}

string PrintSeporator(int i)
{
    string Seporator;
    if (i < 10)
        Seporator = "    |  ";
    else
        Seporator = "   |  ";

    return Seporator;
}

PrintMultiplicationTable()
{
    PrintTableHeader();

    for (int i = 1; i <= 10; i++)
    {
        cout << " " << i << PrintSeporator(i);

        for (int k = 1; k <= 10; k++)
        {
            cout << k * i << '\t';
        }
        cout << "\n";
    }
}

int main(void)
{
    PrintMultiplicationTable();
}