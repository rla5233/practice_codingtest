#include <bitset>

int solution(int N)
{
    int Num = std::bitset<20>(N).count();
    while (Num != std::bitset<20>(++N).count());
    return N;
}