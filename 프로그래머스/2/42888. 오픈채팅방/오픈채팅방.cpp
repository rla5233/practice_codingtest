#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) 
{
    unordered_map<string, string> nickname;
    queue<pair<string, bool>> enterinfo;
    
    for (const string& str : record)
    {
        stringstream ss(str);
        string act = "", id = "", name = "";
        ss >> act >> id >> name;
        
        if ("Enter" == act)
        {
            nickname[id] = name;
            enterinfo.push({ id, true });
        }
        else if ("Leave" == act)
        {
            enterinfo.push({ id, false });
        }
        else
        {
            nickname[id] = name;
        }
    }
    
    vector<string> answer;
    while (!enterinfo.empty())
    {
        string temp = nickname[enterinfo.front().first];
        temp += "님이 ";
        if (enterinfo.front().second)
            temp += "들어왔습니다.";
        else
            temp += "나갔습니다.";        
        
        answer.push_back(temp);
        enterinfo.pop();
    }
    
    return answer;
}