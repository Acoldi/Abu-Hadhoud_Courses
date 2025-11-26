#pragma once

float GetFractionPart(float Number)
{
    return Number - int(Number);
}
