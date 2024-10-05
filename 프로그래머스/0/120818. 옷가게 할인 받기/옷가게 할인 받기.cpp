#include <string>

int solution(int Price) 
{
	if (500000 <= Price)
	{
		Price *= 80;
		Price /= 100;
	}
	else if (300000 <= Price)
	{
		Price *= 90;
		Price /= 100;
	}
	else if (100000 <= Price)
	{
		Price *= 95;
		Price /= 100;
	}

    return Price;
}