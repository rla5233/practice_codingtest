#include <vector>
#include <algorithm>

std::vector<int> solution(std::vector<int> Answers) 
{
    std::vector<std::vector<int>> Num(3);
    Num[0] = {1, 2, 3, 4, 5};
    Num[1] = {2, 1, 2, 3, 2, 4, 2, 5};
    Num[2] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    std::vector<int> Score(3, 0);
    for (int i = 0; i < Answers.size(); ++i)
    {
        if (Answers[i] == Num[0][i % Num[0].size()]) ++Score[0];
        if (Answers[i] == Num[1][i % Num[1].size()]) ++Score[1];
        if (Answers[i] == Num[2][i % Num[2].size()]) ++Score[2];
    }

    std::vector<int> Result;
    int Max = *std::max_element(Score.begin(), Score.end());
    for (int i = 0; i < Score.size(); ++i)
    {
        if (Max == Score[i]) Result.push_back(i + 1);
    }
    
    return Result;
}