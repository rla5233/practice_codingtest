#include <vector>

std::vector<int> solution(std::vector<int> Numbers, int Num1, int Num2) 
{
    return std::vector<int>(Numbers.begin() + Num1, Numbers.begin() + Num2 + 1);
}