#pragma once
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int randomNumber(int From, int To)
{
    int Number;
    Number = rand() % (To - From + 1) + From;
    return Number;
}
