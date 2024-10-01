#include <string>
#include <vector>
#include <cmath>

int solution(int N) 
{
    double Numd = sqrt(N);
    int Numl = static_cast<int>(Numd);
    return (Numd - Numl) == 0.0 ? 1 : 2;
}