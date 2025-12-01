#pragma once
#include <iostream>
#include "GetFractionPart.h"
#include "MyAbs.h" // For abs()

int MyRound(float Number)
{
    int IntPart = int(Number);
    float Fraction = GetFractionPart(Number);

    if (MyAbs(Fraction) >= .5)
    {
        if (Number < 0)
            return --IntPart;
        else{
            return IntPart += 1;
        }
    }
    return IntPart;
}
