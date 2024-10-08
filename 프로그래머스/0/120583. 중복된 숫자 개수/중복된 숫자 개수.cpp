#include <vector>

int solution(std::vector<int> Array, int N) 
{
    int Result = 0;
    for (int Num : Array)
    {
        if (N == Num)
        {
            ++Result;
        }
    }

    return Result;
}