#include <vector>
#include <algorithm>

std::vector<int> solution(std::vector<int> Numbers) 
{
    std::vector<int> Result;
    for (int i = 0; i < Numbers.size() - 1; ++i)
    {
        for (int j = i + 1; j < Numbers.size(); ++j)
        {
            Result.push_back(Numbers[i] + Numbers[j]);
        }
    }

    std::sort(Result.begin(), Result.end());
    Result.erase(std::unique(Result.begin(), Result.end()), Result.end());
    return Result;
}