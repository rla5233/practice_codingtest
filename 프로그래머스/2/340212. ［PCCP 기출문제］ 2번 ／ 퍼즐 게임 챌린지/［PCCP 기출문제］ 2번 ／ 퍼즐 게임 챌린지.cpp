#include <vector>

int solution(std::vector<int> Diffs, std::vector<int> Times, long long Limit) 
{
    int Min = 1, Max = 100000;
    while (Min <= Max)
    {
        size_t CurTime = 0;
        int Mid = (Min + Max) / 2;
        for (int i = 0; i < static_cast<int>(Diffs.size()); ++i)
        {
            if (Mid >= Diffs[i])
                CurTime += Times[i];
            else
                CurTime += (Times[i] + Times[i - 1]) * (Diffs[i] - Mid) + Times[i];
        }

        if (CurTime <= Limit)
            Max = Mid - 1;
        else
            Min = Mid + 1;
    }

    return Min;
}