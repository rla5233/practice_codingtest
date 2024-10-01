#include <string>
#include <vector>
#include <numeric>

int solution(std::string NumStr) 
{
    int Result = std::accumulate(NumStr.begin(), NumStr.end(), 0, [=](int A, char B) { return A + (B - '0'); });
    return Result;
}