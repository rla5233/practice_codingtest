#include <vector>

std::vector<int> solution(int Money) 
{
    return { Money / 5500, Money % 5500 };
}