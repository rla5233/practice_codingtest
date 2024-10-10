#include <algorithm>
#include <vector>
#include <set>

int solution(int N, std::vector<int> Lost, std::vector<int> Reserve)
{
    std::set<int> LostNum, ResNum;
    for (int Num : Reserve)
    {
        ResNum.insert(Num);
    }

    int Result = N - Lost.size();
    for (int Num : Lost)
    {
        if (ResNum.end() != ResNum.find(Num))
        {
            ResNum.erase(ResNum.find(Num));
            ++Result;
        }
        else
        {
            LostNum.insert(Num);
        }
    }
    
    for (int Num : LostNum)
    {       
        if (ResNum.end() != ResNum.find(Num - 1))
        {
            ResNum.erase(ResNum.find(Num - 1));
            ++Result;
            continue;
        }

        if (ResNum.end() != ResNum.find(Num + 1))
        {
            ResNum.erase(ResNum.find(Num + 1));
            ++Result;
            continue;
        }
    }

    return Result;
}