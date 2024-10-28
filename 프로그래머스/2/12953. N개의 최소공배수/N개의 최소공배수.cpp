#include <numeric>
#include <vector>

using namespace std;

int solution(vector<int> Arr) 
{
    int Result = Arr[0];
    for (int i = 1; i < static_cast<int>(Arr.size()); ++i)
    {
        Result = lcm(Result, Arr[i]);
    }

    return Result;
}