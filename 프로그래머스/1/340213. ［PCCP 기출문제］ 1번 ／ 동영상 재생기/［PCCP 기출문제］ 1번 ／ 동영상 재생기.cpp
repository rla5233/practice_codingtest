#include <string>
#include <vector>

int ConvertSec(const std::string& Time)
{
    int M = std::stoi(Time.substr(0, Time.find(':')));
    int S = std::stoi(Time.substr(Time.find(':') + 1));
    return M * 60 + S;
}

int OPCheck(int Start, int End, int Cur)
{
    if (Start <= Cur && End >= Cur)
        Cur = End;

    return Cur;
}

std::string solution(std::string Video_Len, std::string Pos, std::string Op_Start, std::string Op_End, std::vector<std::string> Commands)
{
    int TotalSec = ConvertSec(Video_Len), CurSec = ConvertSec(Pos);
    int O_SSec = ConvertSec(Op_Start), O_ESec = ConvertSec(Op_End);

    CurSec = OPCheck(O_SSec, O_ESec, CurSec);
    for (const auto& Cmd : Commands)
    {
        if ("next" == Cmd)
            (CurSec + 10 > TotalSec) ? CurSec = TotalSec : CurSec += 10;
        else
            (CurSec - 10 < 0) ? CurSec = 0 : CurSec -= 10;

        CurSec = OPCheck(O_SSec, O_ESec, CurSec);
    }

    int M = CurSec / 60, S = CurSec % 60;
    std::string MStr = std::to_string(M);
    MStr.insert(MStr.begin(), 2 - MStr.size(), '0');

    std::string SStr = std::to_string(S);
    SStr.insert(SStr.begin(), 2 - SStr.size(), '0');

    return MStr + ":" + SStr;
}