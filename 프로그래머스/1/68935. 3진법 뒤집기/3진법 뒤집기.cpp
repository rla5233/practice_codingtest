#include <string>
#include <vector>

int solution(int N) 
{
    std::string Ternary = "";
    while (0 != N)
    {
        Ternary += std::to_string(N % 3);
        N /= 3;
    }

    return std::stoi(Ternary, nullptr, 3);
}