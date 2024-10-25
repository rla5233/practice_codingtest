#include <algorithm>
#include <string>
#include <vector>
#include <list>

int solution(std::vector<std::vector<std::string>> Book_Time) 
{
    std::vector<std::pair<int, int>> BookTime;
    for (const auto& CurBook : Book_Time)
    {
        std::string StartH = CurBook[0].substr(0, CurBook[0].find(':'));
        std::string StartM = CurBook[0].substr(CurBook[0].find(':') + 1);
        int Start = 60 * std::stoi(StartH) + std::stoi(StartM);
        
        std::string EndH = CurBook[1].substr(0, CurBook[1].find(':'));
        std::string EndM = CurBook[1].substr(CurBook[1].find(':') + 1);
        int End = 60 * std::stoi(EndH) + std::stoi(EndM);
        
        BookTime.push_back({ Start, End + 10 - Start });
    }
    
    std::sort(BookTime.begin(), BookTime.end());
    
    std::list<int> Using;
    int Remain = 0, Result = 0, PrevTime = 0;
    for (const auto& CurBook : BookTime)
    {
        int CurTime = CurBook.first;
        int Diff = CurTime - PrevTime;
        PrevTime = CurTime;
        for (auto iter = Using.begin(); iter != Using.end();)
        {
            *iter -= Diff;
            if(0 < *iter)
                ++iter;
            else
            {
                iter = Using.erase(iter);
                ++Remain;
            }
        }
        
        if (0 < Remain)
            --Remain;
        else 
            ++Result;
        
        Using.push_back(CurBook.second);        
    }
    
    return Result;
}