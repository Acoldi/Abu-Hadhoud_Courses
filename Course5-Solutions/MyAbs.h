#pragma once

float MyAbs(float Number)
{
    if (Number > 0)
        return Number;    
    else
        return Number*= -1;
}
