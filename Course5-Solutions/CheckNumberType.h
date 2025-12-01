#pragma once

enum enNumberType {Odd=1, Even};

enNumberType CheckNumberType(int number)
{
    int result = number % 2;

    if (result == 0)
    {
        return enNumberType::Even;
    }
    else{
        return enNumberType::Odd;
    }
}
