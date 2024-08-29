#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> solution(std::string String)
{
    std::vector<std::string> Result;

    for (int i = 0; i < String.size(); ++i)
    {
        Result.push_back(String.substr(i));
    }

    std::sort(Result.begin(), Result.end());

    return Result;
}