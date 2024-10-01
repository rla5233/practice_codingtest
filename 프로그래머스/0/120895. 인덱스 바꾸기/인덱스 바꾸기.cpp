#include <string>

std::string solution(std::string MyString, int Num1, int Num2)
{
    std::swap(MyString[Num1], MyString[Num2]);
    return MyString;
}