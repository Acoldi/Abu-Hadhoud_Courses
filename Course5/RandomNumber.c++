#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <time.h>
using namespace std;


int randomNumber(int From, int To)
{
    int Number;
    Number = rand() % (To - From + 1) + From;
    return Number;
}

int main(void)
{
    srand((unsigned)time(NULL));
    cout << randomNumber(5 , 7);
}