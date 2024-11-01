#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool isRange(int H, int W, int Y, int X)
{
    return 0 <= Y && H > Y && 0 <= X && W > X;
}

int solution(vector<vector<int>> Land) 
{
    int H = Land.size(), W = Land[0].size();
    int dy[4] = { 1, -1, 0, 0 }, dx[4] = { 0, 0, -1, 1 };
    vector<vector<bool>> bVisit(H, vector<bool>(W, false));
    
    vector<int> Answer(W, 0);
    for (int x = 0; x < W; ++x)
    {
        queue<pair<int, int>> Q;
        for (int y = 0; y < H; ++y)
        {
            if (0 == Land[y][x] || bVisit[y][x])
                continue;
         
            int Sum = 0, MinX = x, MaxX = x;
            Q.push({y, x});
            bVisit[y][x] = true;
            ++Sum;
            
            while(!Q.empty())
            {
                pair<int, int> Now = Q.front();
                Q.pop();

                MinX > Now.second ? MinX = Now.second : MinX;
                MaxX < Now.second ? MaxX = Now.second : MaxX;
                
                for(int i = 0; i < 4; ++i)
                {
                    int NextY = Now.first + dy[i];
                    int NextX = Now.second + dx[i];
                    if (isRange(H, W, NextY, NextX))
                    {
                        if (1 == Land[NextY][NextX] && !bVisit[NextY][NextX])
                        {
                            Q.push({ NextY, NextX });
                            bVisit[NextY][NextX] = true;
                            ++Sum;
                        }
                    }
                }    
            }
            
            for (int i = MinX; i <= MaxX; ++i)
                Answer[i] += Sum;
        }
    }

    return *max_element(Answer.begin(), Answer.end());
}