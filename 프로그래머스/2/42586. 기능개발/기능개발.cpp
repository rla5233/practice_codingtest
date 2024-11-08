#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> Progresses, vector<int> Speeds) 
{
    queue<pair<int, int>> Q;
    for (int i = 0; i < static_cast<int>(Progresses.size()); ++i)
        Q.push({ Progresses[i], Speeds[i] });
    
    int Day = 1;
    vector<int> Answer;
    while (!Q.empty())
    {
        int Cnt = 0;
        while (!Q.empty() && 100 <= Q.front().first + Day * Q.front().second)
        {
            Q.pop();
            ++Cnt;
        }
        
        if (Cnt)
            Answer.push_back(Cnt);
        
        ++Day;
    }
    
    return Answer;
}