#include <vector>
#include <algorithm>

std::vector<int> solution(std::vector<int> Array, std::vector<std::vector<int>> Commands) 
{
    std::vector<int> Result;
    for (const std::vector<int>& Command : Commands)
    {
        std::vector<int> Temp(Array.begin() + Command[0] - 1, Array.begin() + Command[1]);
        std::sort(Temp.begin(), Temp.end());
        Result.push_back(Temp[Command[2] - 1]);
    }

    return Result;
}