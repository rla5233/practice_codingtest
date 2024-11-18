#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg)
{
    unordered_map<string, int> dic;
    int dicIdx = 1;
    for (int i = 0; i < 26; ++i)
    {
        string alpha = ""; alpha.push_back('A' + i);
        dic[alpha] = dicIdx++;
    }

    vector<int> answer; int msgIdx = 0;
    while (msgIdx < msg.size())
    {
        int size = 2; string temp = msg.substr(msgIdx, size);
        while (msgIdx + size < msg.size() && dic.end() != dic.find(temp))
            temp.push_back(msg[msgIdx + size++]);

        if (dic.end() == dic.find(temp))
        {
            dic[temp] = dicIdx++;
            temp.pop_back();
        }

        answer.push_back(dic[temp]);
        msgIdx += temp.size();
    }
     
    return answer;
}