#include <string>
#include <vector>

std::string solution(std::string NewID) 
{
    std::string Result = "";
    bool End = false;
    for (char C : NewID)
    {
        if (isalpha(C) || isdigit(C) || '-' == C || '_' == C)
        {
            Result += std::tolower(C);
            End = false;
        }
        else if ('.' == C && false == End && !Result.empty())
        {
            Result += C;
            End = true;
        }
    }
    
    if ('.' == Result.back()) 
    { 
        Result.pop_back(); 
    }

    if (Result.empty()) 
    { 
        Result.push_back('a'); 
    }

    if (16 <= Result.size())
    {
        Result.erase(Result.begin() + 15, Result.end());
        if ('.' == Result.back())
        {
            Result.pop_back();
        }
    }

    if (2 >= Result.size())
    {
        while (3 != Result.size())
        {
            Result.push_back(Result.back());
        }
    }

    return Result;
}