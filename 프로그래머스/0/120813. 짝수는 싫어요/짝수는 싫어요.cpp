#include <vector>

std::vector<int> solution(int N) 
{
    std::vector<int> Result;
    for (int i = 1; i <= N; i += 2)
    {
        Result.push_back(i);
    }

    return Result;
}