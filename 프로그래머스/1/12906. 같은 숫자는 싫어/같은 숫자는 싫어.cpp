#include <vector>
#include <algorithm>

std::vector<int> solution(std::vector<int> Arr)
{
    Arr.erase(std::unique(Arr.begin(), Arr.end()), Arr.end());
    return Arr;
}