#include <vector>

using namespace std;

long long solution(int N) 
{
    if (1 == N)
        return 1;
    
    if (2 == N)
        return 2;
    
    long long Result = 0;
    long long Temp1 = 2, Temp2 = 1;
    for (int i = 3; i <= N; ++i)
    {
        Result = (Temp1 + Temp2) % 1234567;
        Temp2 = Temp1;
        Temp1 = Result;
    }
    
    return Result;
}