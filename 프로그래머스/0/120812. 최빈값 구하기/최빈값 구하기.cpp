#include <unordered_map>
#include <vector>

int solution(std::vector<int> Array) 
{
    std::unordered_map<int, int> NumCount;
    for (int Num : Array)
    {
        ++NumCount[Num];
    }
    
    int Result = 0, Max = 0;
    for (const std::pair<int, int>& Pair : NumCount)
    {
        if (Pair.second > Max)
        {
            Max = Pair.second;
            Result = Pair.first;
        }
        else if (Pair.second == Max)
        {
            Result = -1;
        }
    }

    return Result;
}