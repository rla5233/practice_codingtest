#include <string>

std::string solution(std::string Phone_Number) 
{
    std::string Star(Phone_Number.size() - 4, '*');
    return Star + std::string(Phone_Number.end() - 4, Phone_Number.end());
}