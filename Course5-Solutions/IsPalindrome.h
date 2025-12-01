#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include "ReverseNumber.h"

using namespace std;

bool IsPalindrome(int Number)
{
    return Number == ReverseNumber(Number);
}
