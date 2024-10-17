#include <vector>
#include <algorithm>

std::vector<int> solution(std::vector<int> Arr, int Divisor) 
{
    std::vector<int> Result;
    for (int Num : Arr)
    {
        if (0 == Num % Divisor)
            Result.push_back(Num);
    }
            
    std::sort(Result.begin(), Result.end());
    return Result.empty() ? std::vector<int>(1, -1) : Result;
}