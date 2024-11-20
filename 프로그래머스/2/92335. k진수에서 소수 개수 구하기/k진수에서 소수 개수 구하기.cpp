#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(long long num)
{
    if (1 >= num)
        return false;
    
    for (long long i = 2; i * i <= num; ++i)
    {
        if (0 == num % i)
            return false;
    }

    return true;
}

int solution(int n, int k)
{
    string strNum = "";
    vector<long long> vecNum;
    while (0 != n)
    {
        long long mod = n % k;
        if (0 != mod)
        {
            strNum = to_string(mod) + strNum;
        }
        else
        {
            if (!strNum.empty())
            {
                vecNum.push_back(stoll(strNum));
                strNum = "";
            }
        }

        n /= k;
    }

    if (!strNum.empty())
        vecNum.push_back(stoll(strNum));

    int answer = 0;
    for (long long num : vecNum)
    {
        if (isPrime(num))
            ++answer;
    }

    return answer;
}