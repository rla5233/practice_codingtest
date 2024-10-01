#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> solution(std::vector<std::string> Quiz) 
{
    std::vector<std::string> Result;
    
    for (const std::string& Str : Quiz)
    {
        int X = 0, Y = 0, Z = 0;
        char Oper = ' ', Equal = ' ';

        std::stringstream SS(Str);
        SS >> X >> Oper >> Y >> Equal >> Z;
    
        int Answer = 0;
        switch (Oper)
        {
        case '+':
            Answer = X + Y;
            break;
        case '-':
            Answer = X - Y;
            break;
        }

        (Answer == Z) ? Result.push_back("O") : Result.push_back("X");
    }

    return Result;
}