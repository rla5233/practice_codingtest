#include <algorithm>
#include <string>
#include <vector>
#include <queue>

int solution(std::vector<std::vector<std::string>> Book_Time)
{
    std::sort(Book_Time.begin(), Book_Time.end());
    
    int Result = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> Using;
    for (const auto& CurBook : Book_Time)
    {
        std::string SStr = CurBook[0];
        std::string EStr = CurBook[1];
        int S = 60 * std::stoi(SStr.substr(0, 2)) + std::stoi(SStr.substr(3));
        int E = 60 * std::stoi(EStr.substr(0, 2)) + std::stoi(EStr.substr(3)) + 10;
    
        while (!Using.empty() && Using.top() <= S)
            Using.pop();

        Using.push(E);
        Result = std::max(Result, static_cast<int>(Using.size()));
    }

    return Result;
}