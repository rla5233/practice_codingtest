#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> Citations) 
{
    sort(Citations.rbegin(), Citations.rend());
    
    int Answer = 0;
    for (int i = 0; i < static_cast<int>(Citations.size()); ++i)
    {
        if (Citations[i] >= i + 1)
            Answer = i + 1;
    }
    
    return Answer;
}