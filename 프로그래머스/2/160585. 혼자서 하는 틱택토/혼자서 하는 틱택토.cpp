#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool WinCheck(const vector<string>& Board, char Player)
{
    // 가로, 세로
    for (int i = 0; i < Board.size(); ++i)
    {
        if (Board[i][0] == Player && Board[i][1] == Player && Board[i][2] == Player)
            return true;
        if (Board[0][i] == Player && Board[1][i] == Player && Board[2][i] == Player)
            return true;
    }

    // 대각선
    if (Board[0][0] == Player && Board[1][1] == Player && Board[2][2] == Player)
        return true;

    if (Board[0][2] == Player && Board[1][1] == Player && Board[2][0] == Player)
        return true;

    return false;
}

int solution(vector<string> Board) 
{
    int oCnt = 0, xCnt = 0;
    for (const auto& Str : Board)
    {
        oCnt += count(Str.begin(), Str.end(), 'O');
        xCnt += count(Str.begin(), Str.end(), 'X');
    }

    bool oWin = WinCheck(Board, 'O');
    bool xWin = WinCheck(Board, 'X');

    if (oWin && xWin)
        return 0;

    if (oCnt < xCnt || oCnt > xCnt + 1)
        return 0;

    if (oWin && oCnt != xCnt + 1)
        return 0;

    if (xWin && oCnt != xCnt)
        return 0;

    return 1;
}