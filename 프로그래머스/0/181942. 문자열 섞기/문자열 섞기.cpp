#include <string>
#include <vector>

std::string solution(std::string Str1, std::string Str2) 
{
    std::string Result = "";
    
    for(int i = 0; i < Str1.size(); ++i)
    {
        Result += Str1[i];
        Result += Str2[i];
    }
    
    return Result;
}