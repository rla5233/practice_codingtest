#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <string>
#include <vector>

std::vector<int> solution(std::vector<std::string> ID_List, std::vector<std::string> Report, int K) 
{
    std::unordered_map<std::string, std::unordered_set<std::string>> ReportInfo;
    std::unordered_map<std::string, int> ReportCount;
    for (const std::string& Info : Report)
    {
        int SpaceIdx = Info.find(' ');
        std::string ID = Info.substr(0, SpaceIdx);
        std::string RepID = Info.substr(SpaceIdx + 1);

        ReportCount[RepID] += ReportInfo[ID].insert(RepID).second;
    }

    std::vector<int> Result;
    for (const std::string& ID : ID_List)
    {
        int MailCount = 0;
        if (ReportInfo.end() != ReportInfo.find(ID))
        {
            for (const std::string& Info : ReportInfo[ID])
                MailCount += (K <= ReportCount[Info]);
        }

        Result.push_back(MailCount);
    }

    return Result;
}