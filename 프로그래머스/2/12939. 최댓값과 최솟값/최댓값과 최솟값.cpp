#include <string>
#include <sstream>

std::string solution(std::string S) 
{
    std::stringstream SS(S);
    int Num = 0, Min = INT32_MAX, Max = INT32_MIN;
    while (SS >> Num)
    {
        if (Min > Num) Min = Num;
        if (Max < Num) Max = Num;
    }

    return std::to_string(Min) + " " + std::to_string(Max);
}