#include <string>

long long solution(int Price, int Money, int Count)
{
    long long Result = 0;
	for (int i = 1; i <= Count; ++i)
	{
		Result += Price * i;
	}

    return 0 > (Result - Money) ? 0 : Result - Money;
}