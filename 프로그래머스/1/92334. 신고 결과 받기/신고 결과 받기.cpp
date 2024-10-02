#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>

std::vector<int> solution(std::vector<std::string> ID_List, std::vector<std::string> Report, int K) 
{
    std::map<std::string, std::set<std::string>> ReportInfo;
    std::map<std::string, int> ReportCount;
    for (const std::string& Info : Report)
    {
        std::string ID = "", RepID = "";
        std::stringstream SS(Info);
        SS >> ID >> RepID;

        if (ReportInfo[ID].insert(RepID).second)
        {
            ++ReportCount[RepID];
        }
    }

    std::vector<int> Result;
    for (const std::string& ID : ID_List)
    {
        int MailCount = 0;
        if (ReportInfo.end() != ReportInfo.find(ID))
        {
            for (const std::string& Info : ReportInfo[ID])
            {
                if (K <= ReportCount[Info])
                {
                    ++MailCount;
                }
            }
        }

        Result.push_back(MailCount);
    }

    return Result;
}