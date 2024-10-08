#include <vector>

int solution(std::vector<int> Array, int Height)
{
    int Result = 0;
    for (int H : Array)
    {
        if (H > Height)
        {
            ++Result;
        }
    }

    return Result;
}