#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, int p)
{
    const string N = "0123456789ABCDEF";

    --p; string answer = "";
    int curNum = 0, curIdx = 0;
    while (0 != t)
    {
        string strNum = "";
        int temp = curNum++;
        
        do
        {
            strNum = N[temp % n] + strNum;
            temp /= n;
        } 
        while (0 < temp);

        for (char c : strNum)
        {
            if (p == curIdx)
            {
                answer.push_back(c); --t;
                if (0 == t)
                    break;
            }

            curIdx = (curIdx + 1) % m;
        }
    }

    return answer;
}