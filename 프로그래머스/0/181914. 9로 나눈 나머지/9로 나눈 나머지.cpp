#include <string>
#include <vector>

int solution(std::string Numbers) 
{
	int Sum = 0;
	for (const char& Number : Numbers)
	{
		Sum += static_cast<int>(Number - '0');
	}

    return Sum % 9;
}