#include <vector>

using namespace std;

int solution(int N) 
{
    std::vector<int> Temp(N + 1, 0);
    Temp[0] = 0, Temp[1] = 1;
    for (int i = 2; i <= N; ++i)
        Temp[i] = (Temp[i - 2] + Temp[i - 1]) % 1234567;

    int Result = Temp[N];
    return Result;
}