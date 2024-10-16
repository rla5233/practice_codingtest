#include <iostream>
#include <algorithm>
#include <unordered_map>

int main()
{
    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(0); std::cout.tie(0);

    std::unordered_map<std::string, double> GradeInfo = 
    {
        { "A+", 4.5 }, { "A0", 4.0 }, { "B+", 3.5 }, 
        { "B0", 3.0 }, { "C+", 2.5 }, { "C0", 2.0 }, 
        { "D+", 1.5 }, { "D0", 1.0 }, { "F", 0.0 }
    };

    int T = 20;
    double TotalCredit = 0.0, TotalScore = 0.0;
    while (T--)
    {
        std::string Info = "";
        std::getline(std::cin, Info);

        int Idx = Info.find(' ');
        double Credit = std::stod(Info.substr(Idx + 1, 3));
        std::string Grade = Info.substr(Idx + 5);
    
        if ("P" != Grade)
        {
            TotalCredit += Credit;
            TotalScore += Credit * GradeInfo[Grade];
        }
    }

    std::cout << TotalScore / TotalCredit;
    return 0;
}