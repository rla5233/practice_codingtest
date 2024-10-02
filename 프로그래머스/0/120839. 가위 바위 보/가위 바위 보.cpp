#include <string>
#include <map>

std::string solution(std::string Rsp) 
{
    std::string Result = "";
    std::map<char, char> RSP = { { '2', '0' }, { '0', '5' }, { '5', '2' } };
    for (char C : Rsp)
    {
        Result.push_back(RSP[C]);
    }

    return Result;
}