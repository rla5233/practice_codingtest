#include <string>

int BinCount(int N)
{
    int Result = 0;
    while (0 != N)
    {
        if(N & 1)
            ++Result;

        N >>= 1;
    }
    
    return Result;
}

int solution(int N) 
{
    int NCount = BinCount(N), Temp = 0;
    while (NCount != Temp)
    {
        Temp = BinCount(++N);
    }
    
    return N;
}