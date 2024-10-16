#include <vector>

using namespace std;

int solution(int n) 
{
    int answer = 0;

    std::vector<bool> IsPrime(n + 1, true);
    for (int Num = 2; Num <= n; ++Num)
    {
        if (IsPrime[Num])
        {
            for (int i = Num << 1; i < IsPrime.size(); i += Num)
                IsPrime[i] = false;
        }
    }

    for (int i = 2; i < IsPrime.size(); ++i)
    {
        if (IsPrime[i])
            ++answer;
    }

    return answer;
}