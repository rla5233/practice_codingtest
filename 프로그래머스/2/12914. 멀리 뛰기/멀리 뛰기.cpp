#include <vector>

using namespace std;

long long solution(int N) 
{
    vector<long long> Jump(N + 1, 1);
    for(int i = 0; i <= N - 2; ++i)
        Jump[i + 2] = (Jump[i + 1] + Jump[i]) % 1234567;
    
    return Jump[N];
}