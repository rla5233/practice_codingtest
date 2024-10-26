#include <string>
#include <vector>
#include <queue>

using namespace std;

bool isRange(int H, int W, int NextY, int NextX)
{
    return (0 <= NextY && H > NextY && 0 <= NextX && W > NextX);
}

int BFS(const vector<string>& Maps, pair<int, int>& Now, char Target)
{
    int H = Maps.size(), W = Maps[0].size();
    vector<vector<bool>> bVisit(H, vector<bool>(W, false));
    vector<vector<int>> Time(H, vector<int>(W, 0));
    vector<int> dy = { 1, -1, 0, 0 }, dx = { 0, 0, -1, 1 };

    queue<pair<int, int>> Q;
    bVisit[Now.first][Now.second] = true;
    Q.push(Now);

    // BFS
    while (!Q.empty())
    {
        Now = Q.front();
        Q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int NextY = Now.first + dy[i], NextX = Now.second + dx[i];
            if (isRange(H, W, NextY, NextX))
            {
                char Next = Maps[NextY][NextX];
                if ('X' != Next && !bVisit[NextY][NextX])
                {
                    Time[NextY][NextX] = Time[Now.first][Now.second] + 1;
                    Q.push({ NextY, NextX });
                    bVisit[NextY][NextX] = true;

                    if (Target == Next)
                    {
                        Now = { NextY, NextX };
                        return Time[NextY][NextX];
                    }
                }
            }
        }
    }

    return -1;
}

int solution(vector<string> Maps)
{
    // Find Start
    pair<int, int> Now = { -1, -1 };
    for (int i = 0; i < static_cast<int>(Maps.size()); ++i)
    {
        if (string::npos != Maps[i].find('S'))
        {
            Now = { i, Maps[i].find('S') };
            break;
        }
    }

    if (-1 == Now.first)
        return -1;

    // Find Lever
    int TimeL = BFS(Maps, Now, 'L');
    if (-1 == TimeL)
        return -1;

    // Find Exit
    int TimeE = BFS(Maps, Now, 'E');
    if (-1 == TimeE)
        return -1;

    return TimeL + TimeE;
}