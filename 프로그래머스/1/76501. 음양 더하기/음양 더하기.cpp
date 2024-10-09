#include <vector>

int solution(std::vector<int> Absolutes, std::vector<bool> Signs) 
{
    int Result = 0;
    for (int i = 0; i < static_cast<int>(Signs.size()); ++i)
    {
        Signs[i] ? Result += Absolutes[i] : Result -= Absolutes[i];
    }

    return Result;
}