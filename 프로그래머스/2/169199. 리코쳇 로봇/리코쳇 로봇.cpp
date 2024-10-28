#include <string>
#include <vector>
#include <queue>

using namespace std;

bool IsRange(int H, int W, int Y, int X)
{
    return 0 <= Y && H > Y && 0 <= X && W > X;
}

int solution(vector<string> Board) 
{
    int H = Board.size(), W = Board[0].size();

    // Find R
    pair<int, int> Now;
    for (int y = 0; y < H; ++y)
    {
        for (int x = 0; x < W; ++x)
        {
            if ('R' == Board[y][x])
            {
                Now = { y, x };
                break;
            }
        }
    }

    // BFS
    vector<int> dy = { 1, -1, 0, 0 }, dx = { 0, 0, -1, 1 };
    vector<vector<bool>> bVisit(H, vector<bool>(W, false));
    queue<pair<int, int>> Q;
    queue<int> Cost;

    Q.push(Now);
    Cost.push(0);
    bVisit[Now.first][Now.second] = true;

    while (!Q.empty())
    {
        Now = Q.front();
        Q.pop();

        int NowCost = Cost.front();
        Cost.pop();

        for (int i = 0; i < 4; ++i)
        {
            int NextY = Now.first, NextX = Now.second;
            while (IsRange(H, W, NextY + dy[i], NextX + dx[i]) && 'D' != Board[NextY + dy[i]][NextX + dx[i]])
            {
                NextY += dy[i];
                NextX += dx[i];
            }

            if (!bVisit[NextY][NextX])
            {
                bVisit[NextY][NextX] = true;
                Q.push({ NextY, NextX });
                Cost.push(NowCost + 1);

                if ('G' == Board[NextY][NextX])
                    return NowCost + 1;
            }
        }
    }
    
    return -1;
}