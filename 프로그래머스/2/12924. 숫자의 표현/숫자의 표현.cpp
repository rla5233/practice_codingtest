#include <iostream>

int solution(int N) 
{
    int Result = 0;
    int Sum = 1;
    int S = 1, E = 1;
    while (S <= E && E <= N)
    {
        if (N < Sum)
            Sum -= S++;
        else if (N > Sum)
            Sum += ++E;
        else
        {
            ++Result;
            Sum -= S++;
        }
    }
    
    return Result;
}