#include <string>

int solution(int N) 
{
    int Result = 0;
    for (int i = 1; i * i <= N; ++i)
    {
        if (0 == N % i)
        {
            N == i * i ? Result += 1 : Result += 2;
        }
    }

    return Result;
}
