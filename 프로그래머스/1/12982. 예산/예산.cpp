#include <algorithm>
#include <vector>

int solution(std::vector<int> D, int Budget) 
{
    std::sort(D.begin(), D.end());
    
    int Result = 0;
    for (int Money : D)
    {
        if (Budget >= Money)
        {
            Budget -= Money;
            ++Result;
        }
        else
        {
            break;
        }
    }

    return Result;
}