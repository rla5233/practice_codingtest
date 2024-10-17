#include <string>

long long solution(int A, int B) 
{
    long long Result = 0;
    
    if (A <= B)
    {
        for (int i = A; i <= B; ++i)
            Result += i;
    }
    else
    {
        for (int i = B; i <= A; ++i)
            Result += i;
    }

    return Result;
}
