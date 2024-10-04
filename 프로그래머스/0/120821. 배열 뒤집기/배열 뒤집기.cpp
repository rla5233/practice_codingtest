#include <vector>

std::vector<int> solution(std::vector<int> NumList)
{
    return std::vector<int>(NumList.rbegin(), NumList.rend());
}
