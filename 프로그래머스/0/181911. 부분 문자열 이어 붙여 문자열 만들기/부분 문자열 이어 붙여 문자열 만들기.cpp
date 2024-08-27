#include <string>
#include <vector>

std::string solution(std::vector<std::string> My_Strings, std::vector<std::vector<int>> Parts)
{
    std::string Answer = "";

	for (size_t i = 0; i < My_Strings.size(); ++i)
	{
		Answer += My_Strings[i].substr(Parts[i][0], Parts[i][1] - Parts[i][0] + 1);
	}

    return Answer;
}