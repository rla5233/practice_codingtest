#include <vector>

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
            
            ++answer;
        }
    }

    return answer;
}