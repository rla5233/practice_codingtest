#include <string>
#include <vector>
#include <queue>
#include <algorithm>

std::vector<int> solution(std::vector<std::string> Maps)
{
    std::vector<int> dy = { 1, -1, 0, 0 }, dx = { 0, 0, -1, 1 };
    std::vector<std::vector<bool>> bVisited(Maps.size(), std::vector<bool>(Maps[0].size(), false));

    std::vector<int> Result;
    for (int y = 0; y < Maps.size(); ++y)
    {
        for (int x = 0; x < Maps[y].size(); ++x)
        {
            if ('X' != Maps[y][x] && !bVisited[y][x])
            {
                int TotalDay = Maps[y][x] - '0';
                bVisited[y][x] = true;

                std::queue<std::pair<int, int>> Q;
                Q.push({ y, x });

                while (!Q.empty())
                {
                    std::pair<int, int> Now = Q.front();
                    Q.pop();

                    for (int i = 0; i < 4; ++i)
                    {
                        int NextY = Now.first + dy[i];
                        int NextX = Now.second + dx[i];
                        if (0 <= NextY && Maps.size() > NextY && 0 <= NextX && Maps[0].size() > NextX)
                        {
                            if ('X' != Maps[NextY][NextX] && !bVisited[NextY][NextX])
                            {
                                TotalDay += Maps[NextY][NextX] - '0';
                                Q.push({ NextY, NextX });
                                bVisited[NextY][NextX] = true;
                            }
                        }
                    }
                }

                Result.push_back(TotalDay);
            }
        }
    }

    std::sort(Result.begin(), Result.end());
    return Result.empty() ? std::vector<int>(1, -1) : Result;
}