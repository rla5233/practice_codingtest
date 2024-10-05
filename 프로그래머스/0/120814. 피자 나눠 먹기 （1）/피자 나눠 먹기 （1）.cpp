#include <string>

int solution(int N) 
{
    return N % 7 ? (N / 7) + 1 : N / 7;
}