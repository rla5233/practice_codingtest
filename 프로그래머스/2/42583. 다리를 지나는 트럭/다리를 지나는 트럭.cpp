#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
    queue<pair<int, int>> q;
    int answer = 1, total_weight = truck_weights[0], idx = 1;
    q.push({ truck_weights[0], answer });
    
    while (!q.empty())
    {
        ++answer;
        if (bridge_length <= answer - q.front().second)
        {
            total_weight -= q.front().first;
            q.pop();
        }
        
        if (idx < truck_weights.size() && weight >= total_weight + truck_weights[idx])
        {
            q.push({ truck_weights[idx], answer });
            total_weight += truck_weights[idx];
            ++idx;
        }
    }
    
    return answer;
}