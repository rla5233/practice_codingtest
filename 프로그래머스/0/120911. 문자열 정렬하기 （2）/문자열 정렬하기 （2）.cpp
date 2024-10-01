#include <string>
#include <algorithm>

std::string solution(std::string String) 
{
    std::transform(String.begin(), String.end(), String.begin(), ::tolower);
    std::sort(String.begin(), String.end());
    return String;
}