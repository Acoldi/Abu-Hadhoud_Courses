#pragma once
#include <iostream>


using namespace std;

int RandomNumber(int from, int to)
{
	return rand() % (to - from + 1) + from;
}