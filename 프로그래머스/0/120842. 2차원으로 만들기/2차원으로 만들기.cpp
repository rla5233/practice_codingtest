#include <string>
#include <vector>

std::vector<std::vector<int>> solution(std::vector<int> NumList, int N) 
{
    std::vector<std::vector<int>> Result;
    for (int i = 0; i < static_cast<int>(NumList.size()); i += N)
    {
        Result.push_back({ NumList.begin() + i, NumList.begin() + i + N });
    }

    return Result;
}