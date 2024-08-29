#include <string>
#include <vector>

std::vector<std::vector<int>> solution(int N)
{
    std::vector<std::vector<int>> Answer(N, std::vector<int>(N, -1));
    
    std::vector<int> dx = { 1, 0, -1, 0 };
    std::vector<int> dy = { 0, 1, 0, -1 };

    int DirIndex = 0, NCount = 1, y = 0, x = 0;
    while (N * N >= NCount)
    {
        Answer[y][x] = NCount;
        ++NCount;

        int NextX = x + dx[DirIndex];
        int NextY = y + dy[DirIndex];

        if (NextX < 0 || NextX >= Answer[y].size() ||  NextY < 0 || NextY >= Answer.size() || -1 != Answer[NextY][NextX])
        {
            DirIndex = ++DirIndex % 4;
        }

        x += dx[DirIndex];
        y += dy[DirIndex];
    }

    return Answer;
}