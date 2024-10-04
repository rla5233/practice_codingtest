#include <string>

int solution(int N) 
{
    int Result = 0;
    for (int i = 2; i <= N; i += 2)
    {
        Result += i;
    }

    return Result;
}