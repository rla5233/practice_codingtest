#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<int> solution(string _S) 
{
    unordered_map<int, int> Count;
    
    string Temp = "";
    for (char C : _S)
    {
        if (isdigit(C))
            Temp.push_back(C);
        else if ('}' == C || ',' == C)
        {
            if (!Temp.empty())            
            {
                ++Count[stoi(Temp)];
                Temp = "";
            }
        }
    }
    
    priority_queue<pair<int, int>> PQ;
    for (const auto& P : Count)
        PQ.push({ P.second, P.first });
    
    vector<int> Answer;
    while(!PQ.empty())
    {
        Answer.push_back(PQ.top().second);
        PQ.pop();
    }
        
    return Answer;
}