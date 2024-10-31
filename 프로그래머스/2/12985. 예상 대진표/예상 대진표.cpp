#include <algorithm>
#include <vector>

using namespace std;

int solution(int N, int A, int B)
{
    vector<int> AB = { A, B };
    sort(AB.begin(), AB.end());
    
    int Result = 1;
    while(AB[1] - AB[0] != 1 || !(AB[0] & 1))
    {
        for (int& Num : AB)
        {
            if(Num & 1)
                Num = (Num + 1) >> 1;
            else
                Num >>= 1;
        }
        
        ++Result;
    }
    
    return Result;
}