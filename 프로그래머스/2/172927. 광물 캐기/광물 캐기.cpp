#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

bool CmpStone(const vector<int>& A, const vector<int>& B)
{
    return A.back() > B.back();
}

int solution(vector<int> Picks, vector<string> Minerals) 
{
    int PicksCount = accumulate(Picks.begin(), Picks.end(), 0);
    vector<vector<int>> AllScore;
    
    vector<int> Temp(3, 0);
    for (int i = 0; i < Minerals.size(); ++i)
    {
        if ("diamond" == Minerals[i])
            Temp[0] += 1, Temp[1] += 5, Temp[2] += 25;
        else if ("iron" == Minerals[i])
            Temp[0] += 1, Temp[1] += 1, Temp[2] += 5;
        else if ("stone" == Minerals[i])
            Temp[0] += 1, Temp[1] += 1, Temp[2] += 1;
        
        if (0 == (i + 1) % 5 || i == Minerals.size() - 1)
        {
            AllScore.push_back(Temp);
            Temp[0] = 0, Temp[1] = 0, Temp[2] = 0;
            --PicksCount;

            if (0 == PicksCount)
                break;
        }
    }

    sort(AllScore.begin(), AllScore.end(), CmpStone);

    int Result = 0, Idx = 0;
    for (int i = 0; i < AllScore.size(); ++i)
    {
        while (Idx < Picks.size() && 0 == Picks[Idx])
            ++Idx;

        Result += AllScore[i][Idx];
        --Picks[Idx];
    }

    return Result;
}