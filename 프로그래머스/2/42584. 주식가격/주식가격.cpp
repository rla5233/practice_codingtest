#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices)
{
    int size = static_cast<int>(prices.size());
    vector<int> answer(size, 0);

    stack<pair<int, int>> s;
    for (int i = 0; i < size; ++i)
    {
        while (!s.empty() && prices[i] < s.top().first)
        {
            answer[s.top().second] = i - s.top().second;
            s.pop();
        }

        s.push({ prices[i], i });
    }
    
    --size;
    while (!s.empty())
    {
        answer[s.top().second] = size - s.top().second;
        s.pop();
    }

    return answer;
}