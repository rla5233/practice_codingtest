#include <vector>

std::vector<long long> solution(int X, int N) 
{
    std::vector<long long> Result;
    for (int i = 1; i <= N; i++)
    {
        Result.push_back(X * i);
    }

    return Result;
}