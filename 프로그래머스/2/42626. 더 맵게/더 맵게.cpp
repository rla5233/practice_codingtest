#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) 
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int e : scoville)
        pq.push(e);
    
    int answer = 0;
    while (K > pq.top() && 1 < pq.size())
    {
        int temp1 = pq.top(); pq.pop();
        int temp2 = pq.top(); pq.pop();
        
        pq.push(temp1 + (2 * temp2));
        ++answer;
    }
       
    return (1 != pq.size()) ? answer : (K > pq.top()) ? -1 : answer;
}