#include <string>
#include <vector>

std::string solution(std::string String, int N) 
{
	return String.substr(String.size() - N);
}