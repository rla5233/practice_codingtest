#include <string>

using namespace std;

long long solution(long long n) 
{
    long long answer = 0;
    for (size_t i = 1; i * i <= n; ++i)
    {
        if (n == i * i)
            return (i + 1) * (i + 1);
    }

    return -1;
}