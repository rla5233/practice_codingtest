#include <string>

std::string solution(int Age) 
{
    std::string Result = std::to_string(Age);
    for (char& C : Result)
    {
        C += 'a' - '0';
    }

    return Result;
}
