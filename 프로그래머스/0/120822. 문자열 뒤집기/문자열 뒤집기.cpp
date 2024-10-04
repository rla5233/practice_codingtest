#include <string>

std::string solution(std::string MyString) 
{
    return std::string(MyString.rbegin(), MyString.rend());
}