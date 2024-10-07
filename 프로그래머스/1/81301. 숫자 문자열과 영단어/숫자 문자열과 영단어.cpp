#include <string>
#include <regex>

int solution(std::string S) 
{
    S = std::regex_replace(S, std::regex("zero"), "0");
    S = std::regex_replace(S, std::regex("one"), "1");
    S = std::regex_replace(S, std::regex("two"), "2");
    S = std::regex_replace(S, std::regex("three"), "3");
    S = std::regex_replace(S, std::regex("four"), "4");
    S = std::regex_replace(S, std::regex("five"), "5");
    S = std::regex_replace(S, std::regex("six"), "6");
    S = std::regex_replace(S, std::regex("seven"), "7");
    S = std::regex_replace(S, std::regex("eight"), "8");
    S = std::regex_replace(S, std::regex("nine"), "9");
    return std::stoi(S);
}