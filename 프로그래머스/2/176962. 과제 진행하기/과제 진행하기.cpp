#include <string>
#include <vector>
#include <stack>
#include <map>

using namespace std;

vector<string> solution(vector<vector<string>> Plans) 
{
    map<int, pair<string, int>> Works;
    for (const auto& Plan : Plans)
    {
        int Start = stoi(Plan[1].substr(0, 2)) * 60 + stoi(Plan[1].substr(3));
        Works[Start] = { Plan[0], stoi(Plan[2]) };
    }
    
    vector<string> Result;
    stack<pair<string, int>> Remain;
    int Prev = Works.begin()->first;
    for (auto it = ++Works.begin(); it != Works.end(); ++it)
    {
        int Cur = it->first;
        int WorkTime = Cur - Prev;

        if (Works[Prev].second > WorkTime)
            Remain.push({ Works[Prev].first, Works[Prev].second - WorkTime });
        else
        {
            Result.push_back(Works[Prev].first);
            WorkTime -= Works[Prev].second;
            while (!Remain.empty() && 0 != WorkTime)
            {
                if (Remain.top().second > WorkTime)
                {
                    Remain.top().second -= WorkTime;
                    WorkTime = 0;
                }
                else
                {
                    WorkTime -= Remain.top().second;
                    Result.push_back(Remain.top().first);
                    Remain.pop();
                }
            }
        }
        
        Prev = Cur;
    }
    
    Result.push_back(Works[Prev].first);
    while (!Remain.empty())
    {
        Result.push_back(Remain.top().first);
        Remain.pop();
    }

    return Result;
}