#include <vector>

std::vector<int> solution(std::vector<int> Lottos, std::vector<int> WinNums) 
{
    std::vector<int> Grade = { 6, 6, 5, 4, 3, 2, 1 };

    int WinCount = 0, UnKnown = 0;
    for (int Lotto : Lottos)
    {
        if (0 == Lotto)
        {
            ++UnKnown;
        }
        else
        {
            for (int WinNum : WinNums)
            {
                if (Lotto == WinNum)
                {
                    ++WinCount;
                }
            }
        }
    }

    return { Grade[WinCount + UnKnown], Grade[WinCount] };
}