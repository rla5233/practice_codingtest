#include <string>
#include <map>
#include <set>

using namespace std;

bool isRange(pair<int, int> pos)
{
    return -5 <= pos.first && 5 >= pos.first && -5 <= pos.second && 5 >= pos.second;
}

int solution(string dirs)
{
    map<char, pair<int, int>> dir = 
    { 
        { 'U', { 0, 1 } }, { 'D', { 0, -1 } }, 
        { 'R', { 1, 0 } }, { 'L', { -1, 0 } } 
    };
 
    int answer = 0;
    pair<int, int> curPos = { 0, 0 };
    map<pair<int, int>, set<pair<int, int>>> check;
    for (char c : dirs)
    {
        pair<int, int> nextPos = { curPos.first + dir[c].first, curPos.second + dir[c].second };
        if (isRange(nextPos))
        {
            if (check[curPos].end() == check[curPos].find(nextPos))
            {
                check[curPos].insert(nextPos);
                check[nextPos].insert(curPos);
                ++answer;
            }

            curPos = nextPos;
        }
    }

    return answer;
}