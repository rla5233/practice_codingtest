#include <vector>
#include <map>

std::vector<int> solution(int N, std::vector<int> Stages) 
{
    std::vector<int> Failed(N + 2, 0), All(N + 2, 0);
    for (int Stage : Stages)
    {
        for (int i = 1; i < Stage; ++i)
        {
            ++All[i];
        }

        ++All[Stage];
        ++Failed[Stage];
    }

    std::multimap<double, int, std::greater<double>> Sort;
    for (int i = 1; i <= N; ++i)
    {
        double Prob = Failed[i] / static_cast<double>(All[i]);
        Sort.insert({ Prob, i });
    }

    std::vector<int> Result;
    for (const std::pair<double, int>& Info : Sort)
    {
        Result.push_back(Info.second);
    }

    return Result;
}