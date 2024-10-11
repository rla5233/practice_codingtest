#include <vector>

std::vector<std::vector<int>> solution(std::vector<std::vector<int>> Arr1, std::vector<std::vector<int>> Arr2)
{
    std::vector<std::vector<int>> Result(Arr1.size(), std::vector<int>(Arr1[0].size(), 0));
    for (int y = 0; y < Arr1.size(); ++y)
    {
        for (int x = 0; x < Arr1[y].size(); ++x)
        {
            Result[y][x] = Arr1[y][x] + Arr2[y][x];
        }
    }

    return Result;
}