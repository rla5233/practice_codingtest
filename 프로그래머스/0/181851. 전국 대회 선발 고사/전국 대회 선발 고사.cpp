#include <string>
#include <vector>
#include <algorithm>

int solution(std::vector<int> Rank, std::vector<bool> Attendance) 
{
    std::vector<std::pair<int, int>> NewRank;
    for (size_t i = 0; i < Attendance.size(); ++i)
    {
        if (Attendance[i])
        {
            NewRank.push_back({ Rank[i], i });
        }
    }
    
    std::sort(NewRank.begin(), NewRank.end());

    return (10000 * NewRank[0].second) + (100 * NewRank[1].second) + NewRank[2].second;
}