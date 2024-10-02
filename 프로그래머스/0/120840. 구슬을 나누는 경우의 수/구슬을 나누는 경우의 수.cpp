#include <string>

int solution(int Balls, int Share) 
{
    long long Result = 1;
    for (int i = 0; i < Share; ++i)
    {
        Result *= Balls - i;
        Result /= 1 + i;
    }

    return Result;
}