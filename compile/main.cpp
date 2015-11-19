#include "stdio.h"

float s(float a)
{
    static const float f = 1.f / 1002.f;
    return a * f;
}

int main()
{
    float f = 1.f;
    auto a = f / 412343;
    auto b = f * 0.02231f;
    auto c = s(a);
    
    return a * b;
}
