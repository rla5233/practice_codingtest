#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) 
{
    stack<int> sub;
    int answer = 0, box = 1, idx = 0;
    while(true)
    {
        if (box < order[idx])
            sub.push(box++);
        else if (box == order[idx])
            ++answer, ++idx, ++box;
        else if (!sub.empty() && sub.top() == order[idx])
            ++answer, ++idx, sub.pop();
        else
            break;
    }
        
    return answer;
}