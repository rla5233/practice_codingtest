#include <vector>
#include <unordered_map>
#include <algorithm>

std::vector<int> solution(std::vector<int> Emergency) 
{
    std::vector<int> Temp = Emergency;
    std::sort(Temp.rbegin(), Temp.rend());

    std::unordered_map<int, int> Sort;
    for (int i = 0; i < static_cast<int>(Temp.size()); ++i)
    {
        Sort[Temp[i]] = i + 1;
    }
    
    std::vector<int> Result;
    for (int i = 0; i < static_cast<int>(Emergency.size()); ++i)
    {
        Result.push_back(Sort[Emergency[i]]);
    }

    return Result;
}