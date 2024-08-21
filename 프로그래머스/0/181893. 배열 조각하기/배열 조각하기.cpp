#include <string>
#include <vector>

std::vector<int> solution(std::vector<int> Arr, std::vector<int> Query)
{
    std::vector<int> Result = Arr;

    for (int i = 0; i < Query.size(); ++i)
    {
        if (0 == i % 2)
        {
            Result = std::vector(Result.begin(), Result.begin() + Query[i] + 1);            
        }
        else
        {
            Result = std::vector(Result.begin() + Query[i], Result.end());     
        }
    }

    return Result;
}