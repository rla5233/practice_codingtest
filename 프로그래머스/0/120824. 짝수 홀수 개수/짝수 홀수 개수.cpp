#include <vector>

std::vector<int> solution(std::vector<int> NumList) 
{
    std::vector<int> Result(2, 0);
    for (int Num : NumList) 
    {
        Num % 2 ? ++Result[1] : ++Result[0];
    }

    return Result;
}