#include <cmath>

using namespace std;

long long solution(int R1, int R2) 
{
    long long Result = 0, r1 = R1, r2 = R2;
    for (long long x = 1; x <= R2; ++x)
    {
        long long MaxY = floor(sqrt(r2 * r2 - x * x));
        long long MinY = (x < R1) ? ceil(sqrt(r1 * r1 - x * x)) : 0;
        Result += MaxY - MinY + 1;
    }

    return 4 * Result;
}