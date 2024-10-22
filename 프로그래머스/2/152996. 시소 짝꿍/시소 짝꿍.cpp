#include <vector>
#include <algorithm>

long long solution(std::vector<int> Weights)
{
    std::sort(Weights.begin(), Weights.end());

    long long Result = 0;
    for (int i = 0; i < static_cast<int>(Weights.size()) - 1; ++i)
    {
        for (int j = i + 1; j < Weights.size(); ++j)
        {
            if (Weights[i] == Weights[j])
                ++Result;
            else if (4 * Weights[i] == 2 * Weights[j])
                ++Result;
            else if (4 * Weights[i] == 3 * Weights[j])
                ++Result;
            else if (3 * Weights[i] == 2 * Weights[j])
                ++Result;
        }
    }

    return Result;
}