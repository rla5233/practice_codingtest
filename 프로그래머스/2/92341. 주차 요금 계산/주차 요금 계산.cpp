#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records)
{
    map<int, int> timeinfo;
    unordered_map<int, int> car;
    for (const string& record : records)
    {
        int time = 60 * stoi(record.substr(0, 2)) + stoi(record.substr(3, 2));
        int number = stoi(record.substr(6, 4));

        if ("IN" == record.substr(11, 2))
        {
            car[number] = time;
        }
        else
        {
            timeinfo[number] += time - car[number];
            car.erase(number);
        }
    }

    for (const auto& pair : car)
        timeinfo[pair.first] += 1439 - pair.second;

    vector<int> answer;
    for (const auto& pair : timeinfo)
    {
        int fee = fees[1];
        if (fees[0] < pair.second)
            fee += fees[3] * ceil((pair.second - fees[0]) / static_cast<double>(fees[2]));

        answer.push_back(fee);
    }

    return answer;
}