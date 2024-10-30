#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> People, int Limit) 
{
    sort(People.begin(), People.end());

    int Result = 0;
    int Left = 0, Right = People.size() - 1;
    while (Left <= Right)
    {
        if (Limit >= People[Left] + People[Right])
            ++Left;
        
        --Right; ++Result;
    }

    return Result;
}