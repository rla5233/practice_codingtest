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

        switch (DirIndex)
        {
        case 0:
            
            if (NextX >= Answer[y].size() || -1 != Answer[y][NextX])
            {
                DirIndex = ++DirIndex % 4;
            }
            break;
        case 1:
            if (NextY >= Answer.size() || -1 != Answer[NextY][x])
            {
                DirIndex = ++DirIndex % 4;
            }
            break;
        case 2:
            if (NextX < 0 || -1 != Answer[y][NextX])
            {
                DirIndex = ++DirIndex % 4;
            }
            break;
        case 3:
            if (NextY < 0 || -1 != Answer[NextY][x])
            {
                DirIndex = ++DirIndex % 4;
            }
            break;
        }

        x += dx[DirIndex];
        y += dy[DirIndex];
    }

    return Answer;
}