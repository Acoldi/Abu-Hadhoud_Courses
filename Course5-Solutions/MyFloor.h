#pragma once

int MyFloor(float Number)
{
    int IntPart = int(Number);
    if (Number > 0)
        return IntPart;
    else
        return --IntPart;
}
