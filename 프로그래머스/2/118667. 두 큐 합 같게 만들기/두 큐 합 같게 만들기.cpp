#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2)
{
    queue<int> q1, q2;
    long long sumL = 0, sumR = 0;
    int size = static_cast<int>(queue1.size());
    for (int i = 0; i < size; ++i)
    {
        sumL += queue1[i], q1.push(queue1[i]);
        sumR += queue2[i], q2.push(queue2[i]);
    }

    int answer = 0;
    size *= 3;
    while (sumL != sumR)
    {
        if (size <= answer)
            return -1;

        if (sumL > sumR)
        {
            sumL -= q1.front();
            sumR += q1.front();
            q2.push(q1.front());
            q1.pop();
        }
        else
        {
            sumL += q2.front();
            sumR -= q2.front();
            q1.push(q2.front());
            q2.pop();
        }

        ++answer;
    }

    return answer;
}