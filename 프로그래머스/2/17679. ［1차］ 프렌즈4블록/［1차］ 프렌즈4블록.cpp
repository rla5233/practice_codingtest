#include <string>
#include <vector>

#define TL(c) tolower(c)

using namespace std;

void checkFBlock(int y, int x, vector<string>& b)
{
    char temp = TL(b[y][x]);
    if (TL(b[y][x + 1]) == temp && TL(b[y + 1][x]) == temp && TL(b[y + 1][x + 1]) == temp)
    {
        b[y][x] = temp; b[y][x + 1] = temp; 
        b[y + 1][x] = temp; b[y + 1][x + 1] = temp;
    }
}

int deleteFBlock(int y, int x, vector<string>& board)
{
    int cnt = 0;
    vector<int> empty(x, -1);
    for (int i = y - 1; i >= 0; --i)
    {
        for (int j = x - 1; j >= 0; --j)
        {
            if (islower(board[i][j]))
            {
                board[i][j] = ' ', ++cnt;
                if (-1 == empty[j])
                    empty[j] = i;
            }
        }
    }

    for (int j = 0; j < x; ++j)
    {
        int a = 0;

        if (-1 != empty[j])
        {
            for (int i = empty[j] - 1; i >= 0; --i)
            {
                if (' ' != board[i][j])
                {
                    board[empty[j]--][j] = board[i][j];
                    board[i][j] = ' ';
                }
            }
        }
    }

    return cnt;
}

int solution(int m, int n, vector<string> board) 
{
    int answer = 0;
    while (true)
    {
        for (int y = 0; y < m - 1; ++y)
        {
            for (int x = 0; x < n - 1; ++x)
            {
                checkFBlock(y, x, board);
            }
        }
        
        int delcnt = deleteFBlock(m, n, board);
        if (0 == delcnt)
            break;

        answer += delcnt;
    
    }
    
    return answer;
}