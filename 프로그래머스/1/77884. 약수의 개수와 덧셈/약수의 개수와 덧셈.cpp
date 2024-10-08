#include <string>
#include <cmath>

int solution(int Left, int Right) 
{
    int Result = 0;
    for (int i = Left; i <= Right; ++i)
    {
        int sqrti = sqrt(i);
        0 == (sqrt(i) - sqrti) ? Result -= i : Result += i;
    }

    return Result;
}