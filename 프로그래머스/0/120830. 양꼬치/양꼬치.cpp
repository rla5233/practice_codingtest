#include <string>

int solution(int N, int K) 
{
    int Result = N * 12000;
    K -= N / 10;
    Result += K * 2000;
    return Result;
}