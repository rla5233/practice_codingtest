#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool IsRange(int h, int w, int y, int x)
{
    return 0 <= y && h > y && 0 <= x && w > x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int m = 0, n = 0, k = 0;
    cin >> m >> n >> k;

    vector<vector<bool>> board(m, vector<bool>(n, true));
    while (k--)
    {
        int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int y = y1; y < y2; ++y)
        {
            for (int x = x1; x < x2; ++x)
            {
                board[y][x] = false;
            }
        }
    }

    vector<int> area;
    int dy[4] = { 1, -1, 0, 0 }, dx[4] = { 0, 0, -1, 1 };
    for (int y = 0; y < m; ++y)
    {
        for (int x = 0; x < n; ++x)
        {
            if (board[y][x])
            {
                int size = 1;
                queue<pair<int, int>> q;
                board[y][x] = false;
                q.push({ y, x });

                while (!q.empty())
                {
                    pair<int, int> now = q.front();
                    q.pop();

                    for (int i = 0; i < 4; ++i)
                    {
                        pair<int, int> next = { now.first + dy[i], now.second + dx[i] };
                        if (IsRange(m, n, next.first, next.second))
                        {
                            if (board[next.first][next.second])
                            {
                                board[next.first][next.second] = false;
                                q.push(next);
                                ++size;
                            }
                        }
                    }
                }

                area.push_back(size);
            }
        }
    }

    sort(area.begin(), area.end());
    cout << area.size() << '\n';
    for (int e : area)
        cout << e << ' ';

    return 0;
}