#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> Citations) 
{
    sort(Citations.rbegin(), Citations.rend());
    
    int Answer = 0, Cnt = 0;
    for (int i = 0; i < static_cast<int>(Citations.size()); ++i)
    {
        ++Cnt;
        if (Citations[i] >= Cnt)
            Answer = Cnt;
    }
    
    return Answer;
}