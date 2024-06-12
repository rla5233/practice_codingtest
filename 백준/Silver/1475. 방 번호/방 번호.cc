#include <iostream>
#include <vector>
#include <cmath>

int main()
{
	int N = 0;
	std::cin >> N;

	std::vector<int> NumVec(10, 0);
	while (0 != N)
	{
		++NumVec[N % 10];
		N /= 10;
	}

	NumVec[6] += NumVec[9];
	NumVec[6] = static_cast<int>(ceil(NumVec[6] / 2.0));

	int SetCount = 0;
	for (size_t i = 0; i < NumVec.size() - 1; i++)
	{
		if (SetCount < NumVec[i])
		{
			SetCount = NumVec[i];
		}
	}
	
	std::cout << SetCount;
    
    return 0;
}