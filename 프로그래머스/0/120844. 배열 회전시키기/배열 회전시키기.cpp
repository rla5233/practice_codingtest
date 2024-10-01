#include <string>
#include <vector>
#include <algorithm>

std::vector<int> solution(std::vector<int> Numbers, std::string Direction) 
{
    if ("right" == Direction)
    {
        std::rotate(Numbers.begin(), Numbers.end() - 1, Numbers.end());
    }
    else
    {
        std::rotate(Numbers.begin(), Numbers.begin() + 1, Numbers.end());
    }

    return Numbers;
}