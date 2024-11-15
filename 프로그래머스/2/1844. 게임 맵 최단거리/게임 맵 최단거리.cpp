#include<vector>
#include<queue>

using namespace std;

bool isRange(int _H, int _W, int _Y, int _X)
{
    return 0 <= _Y && _H > _Y && 0 <= _X && _W > _X;
}

int solution(vector<vector<int>> _Maps)
{
    int H = _Maps.size(), W = _Maps[0].size();
    vector<vector<bool>> bVisit(H, vector<bool>(W, false));
    int dy[4] = { -1, 1, 0 ,0 }, dx[4] = { 0, 0, -1, 1 };
    
    queue<pair<int, int>> Q;
    Q.push({ 0, 0 });
    bVisit[0][0] = true;
    
    while (!Q.empty())
    {
        pair<int, int> Now = Q.front();
        Q.pop();
        
        for (int i = 0; i < 4; ++i)
        {
            int NextY = Now.first + dy[i], NextX = Now.second + dx[i];
            if (isRange(H, W, NextY, NextX))
            {
                if (0 != _Maps[NextY][NextX] && !bVisit[NextY][NextX])
                {
                    _Maps[NextY][NextX] = _Maps[Now.first][Now.second] + 1;
                    bVisit[NextY][NextX] = true; 
                    Q.push({ NextY, NextX });
                    
                    if (H - 1 == NextY && W - 1 == NextX)
                        return _Maps[NextY][NextX];
                }
            }
        }
    }

    return -1;
}