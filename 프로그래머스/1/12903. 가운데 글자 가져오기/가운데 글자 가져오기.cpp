#include <string>

std::string solution(std::string s) 
{
    int Size = s.size();
    return (Size & 1) ? s.substr(Size / 2, 1) : s.substr(Size / 2 - 1, 2);
}