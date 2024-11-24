#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) 
{
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    int answer = 0;
    while (K > pq.top())
    {
        if (1 == pq.size())
            return -1;
        
        int temp1 = pq.top(); pq.pop();
        int temp2 = pq.top(); pq.pop();
        pq.push(temp1 + (2 * temp2));
        ++answer;
    }
       
    return answer;
}