#pragma once
#include "GetFractionPart.h"

int MyCeil(float Number)
{
    if (GetFractionPart(Number) > 0)
    {
        int IntPart = int(Number);
        if (Number > 0)
            return ++IntPart;
        else
            return IntPart;
    }
    return Number;
}
