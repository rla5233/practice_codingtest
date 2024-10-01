#include <string>
#include <vector>

std::string solution(std::vector<int> Foods) 
{
    std::string Result = "";
    for (int i = 1; i < Foods.size(); ++i)
    {
        for (int j = 0; j < Foods[i] / 2; ++j)
        {
            Result += std::to_string(i);
        }
    }

    std::string Temp(Result.rbegin(), Result.rend());
    Result += "0" + Temp;
    return Result;
}