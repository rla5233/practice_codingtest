#include <string>
#include <vector>
#include <map>

std::string solution(std::vector<std::string> Survey, std::vector<int> Choices) 
{
    char MBTI[4][2] = { { 'R', 'T' }, { 'C', 'F' }, { 'J', 'M' }, { 'A', 'N' } };
    int Score[7] = {3, 2, 1, 0, -1, -2, -3};

    std::map<char, int> MBTIScore;
    for (int i = 0; i < Survey.size(); ++i)
    {
        if (Choices[i] < 4)
        {
            MBTIScore[Survey[i][0]] += Score[Choices[i] - 1];
        }
        else
        {
            MBTIScore[Survey[i][1]] -= Score[Choices[i] - 1];
        }
    }

    std::string Result = "";
    for (int i = 0; i < 4; ++i)
    {
        if (MBTIScore[MBTI[i][0]] >= MBTIScore[MBTI[i][1]])
        {
            Result.push_back(MBTI[i][0]);
        }
        else
        {
            Result.push_back(MBTI[i][1]);
        }
    }
    
    return Result;
}