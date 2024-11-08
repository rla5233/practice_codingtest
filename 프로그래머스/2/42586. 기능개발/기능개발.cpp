#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> Progresses, vector<int> Speeds) 
{
    vector<int> Answer;
    int MaxDay = -1;
    for (int i = 0; i < static_cast<int>(Progresses.size()); ++i)
    {
        int Day = (99 - Progresses[i]) / Speeds[i] + 1;
        
        if (MaxDay < Day)
        {
            Answer.push_back(1);
            MaxDay = Day;
        }
        else
            ++Answer.back();
    }
    
    return Answer;
}