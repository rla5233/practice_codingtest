#include <vector>

int solution(std::vector<int> Dot) 
{
	if (0 < Dot[0] && 0 < Dot[1])
	{
		return 1;
	}
	else if (0 > Dot[0] && 0 < Dot[1])
	{
		return 2;
	}
	else if (0 > Dot[0] && 0 > Dot[1])
	{
		return 3;
	}
	else
	{
		return 4;
	}
}