#include <string>
#include <vector>

std::string solution(std::string String, std::vector<int> Index_List) 
{
    std::string Answer = "";

	for (size_t i = 0; i < Index_List.size(); ++i)
	{
		Answer += String[Index_List[i]];
	}

    return Answer;
}