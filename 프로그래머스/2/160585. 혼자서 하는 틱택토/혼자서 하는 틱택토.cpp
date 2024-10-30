#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> Board) 
{
    int Cnt_O = 0, Cnt_X = 0;
    bool Win_O = false, Win_X = false;

    vector<string> H(3, "");
    for (const auto& Str : Board)
    {
        Cnt_O += count(Str.begin(), Str.end(), 'O');
        Cnt_X += count(Str.begin(), Str.end(), 'X');

        if ("OOO" == Str)
            Win_O = true;

        if ("XXX" == Str)
            Win_X = true;

        H[0] += Str[0];
        H[1] += Str[1];
        H[2] += Str[2];
    }

    for (auto& Str : H)
    {
        if ("OOO" == Str)
            Win_O = true;

        if ("XXX" == Str)
            Win_X = true;
    }

    string Dia1 = "", Dia2 = "";
    for (int i = 0; i < 3; ++i)
    {
        Dia1 += Board[i][i];
        Dia2 += Board[i][2 - i];
    }

    if ("OOO" == Dia1)
        Win_O = true;

    if ("XXX" == Dia1)
        Win_X = true;

    if ("OOO" == Dia2)
        Win_O = true;

    if ("XXX" == Dia2)
        Win_X = true;

    if (Cnt_O < Cnt_X || Cnt_O > Cnt_X + 1)
        return 0;

    if (Win_O && Win_X)
        return 0;

    if (Win_O && Cnt_O != Cnt_X + 1)
        return 0;

    if (Win_X && Cnt_O != Cnt_X)
        return 0;

    return 1;
}