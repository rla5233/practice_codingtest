#include <iostream>
using namespace std;

int solution(int N)
{
    int Result = 0;
    while (0 != N)
    {
        if (N & 1)
            --N, ++Result;
        else
            N >>= 1;
    }

    return Result;
}