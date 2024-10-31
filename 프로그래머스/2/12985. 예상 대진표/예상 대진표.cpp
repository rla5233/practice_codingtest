#include <iostream>

using namespace std;

int solution(int N, int A, int B)
{
    A--, B--;
    int Result = 0;
    while(A != B)
    {
        A >>= 1;
        B >>= 1;
        ++Result;
    }
    
    return Result;
}