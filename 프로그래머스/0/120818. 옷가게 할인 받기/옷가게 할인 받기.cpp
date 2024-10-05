#include <string>

int solution(int Price) 
{
	if (500000 <= Price)
	{
		Price *= 0.8;
	}
	else if (300000 <= Price)
	{
		Price *= 0.9;
	}
	else if (100000 <= Price)
	{
		Price *= 0.95;
	}

    return Price;
}