#include <string>
#include <vector>

long long solution(std::string Numbers)
{
        std::vector<std::string> Num = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    for (int i = 0; i < Num.size(); ++i)
    {
        int Index = Numbers.find(Num[i]);
        while(std::string::npos != Index)
        {
            Numbers.replace(Index, Num[i].size(), std::to_string(i));
            Index = Numbers.find(Num[i]);
        }
    }

    return std::stoll(Numbers);
}