#include <vector>
#include <algorithm>

std::vector<int> solution(std::vector<int> Numbers) 
{
    std::transform(Numbers.begin(), Numbers.end(), Numbers.begin(), [](int Num) { return Num * 2; });
    return Numbers;
}