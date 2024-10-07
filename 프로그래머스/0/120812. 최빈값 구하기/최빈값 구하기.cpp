#include <unordered_map>
#include <vector>
#include <map>

int solution(std::vector<int> Array) 
{
    std::unordered_map<int, int> NumCount;
    std::multimap<int, int> Mode;
    for (int Num : Array)
    {
        ++NumCount[Num];
    }
    
    for (const std::pair<int, int>& Num : NumCount)
    {
        Mode.insert({ Num.second, Num.first });
    }

    return 1 == Mode.count(Mode.rbegin()->first) ? Mode.rbegin()->second : -1;
}