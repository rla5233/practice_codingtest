#include <string>
#include <sstream>

int solution(std::string String) 
{
    char Oper = ' ';
    int Result = 0, Temp = 0;
    std::stringstream SS(String);
    SS >> Result;

    while (SS >> Oper >> Temp)
    {
        switch (Oper)
        {
        case '+':
            Result += Temp;
            break;
        case '-':
            Result -= Temp;
            break;
        }
    }

    return Result;
}