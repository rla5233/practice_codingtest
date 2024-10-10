#include <string>
#include <vector>
#include <unordered_map>

std::string solution(std::vector<int> Numbers, std::string Hand) 
{
    std::unordered_map<int, std::pair<int, int>> Left, Mid, Right;
    Left[1] = { 0, 0 }, Left[4] = { 1, 0 }, Left[7] = { 2, 0 };
    Mid[2] = { 0, 1 }, Mid[5] = { 1, 1 }, Mid[8] = { 2, 1 }, Mid[0] = { 3, 1 };
    Right[3] = { 0, 2 }, Right[6] = { 1, 2 }, Right[9] = { 2, 2 };

    std::string Result = "";
    std::pair<int, int> CurL = { 3, 0 }, CurR = { 3, 2 };
    for (int Num : Numbers)
    {
        if (Left.end() != Left.find(Num))
        {
            CurL = Left[Num];
            Result.push_back('L');
            continue;
        }

        if (Right.end() != Right.find(Num))
        {
            CurR = Right[Num];
            Result.push_back('R');
            continue;
        }

        int LDiff = abs(CurL.first - Mid[Num].first) + abs(CurL.second - Mid[Num].second);
        int RDiff = abs(CurR.first - Mid[Num].first) + abs(CurR.second - Mid[Num].second);

        if (LDiff == RDiff)
        {
            if ("left" == Hand)
            {
                CurL = Mid[Num];
                Result.push_back('L');
            }
            else
            {
                CurR = Mid[Num];
                Result.push_back('R');
            }

            continue;
        }

        if (LDiff < RDiff)
        {
            CurL = Mid[Num];
            Result.push_back('L');
        }
        else
        {
            CurR = Mid[Num];
            Result.push_back('R');
        }
    }

    return Result;
}