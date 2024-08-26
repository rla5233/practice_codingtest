#include <string>
#include <vector>

std::vector<int> solution(int N) 
{
    std::vector<int> Answer(1, N);
  
	while (1 != N)
	{
		if (0 == N % 2)
		{
			N /= 2;
		}
		else
		{
			N = 3 * N + 1;
		}

		Answer.push_back(N);
	}

	return Answer;
}