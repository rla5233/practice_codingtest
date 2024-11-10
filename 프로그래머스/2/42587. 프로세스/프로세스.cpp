#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> _Priorities, int _Location) 
{
    priority_queue<int> PQ;
    queue<pair<int, int>> Q;
    for (int i = 0; i < static_cast<int>(_Priorities.size()); ++i)
    {
        PQ.push(_Priorities[i]);
        Q.push({ _Priorities[i], i });
    }
    
    int Answer = 1;
    while (!Q.empty())
    {
        while (PQ.top() != Q.front().first)
        {
            Q.push(Q.front());
            Q.pop();
        }
        
        if (_Location == Q.front().second)
            break;
        
        Q.pop();                
        PQ.pop();    
        ++Answer;            
    }
    
    return Answer;
}