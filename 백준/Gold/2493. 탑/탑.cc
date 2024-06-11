#include <iostream>
#include <stack>
#include <vector>

struct Top
{
	int Height = 0;
	int Idx = 0;
};

int main()
{
	int N = 0;
	std::cin >> N;
	
	std::stack<Top> Stack;
	for (int i = 0; i < N; i++)
	{
		int H = 0;
		std::cin >> H;

		Top NewTop(H, i);
		Stack.push(NewTop);
	}

	std::vector<int> Result(N, 0);
	std::stack<Top> Temp;
	while (false == Stack.empty())
	{
		if (true == Temp.empty())
		{
			Temp.push(Stack.top());
			Stack.pop();
		}
		else
		{
			if (Stack.top().Height > Temp.top().Height)
			{
				Result[Temp.top().Idx] = static_cast<int>(Stack.size());
				Temp.pop();
			}
			else
			{
				Temp.push(Stack.top());
				Stack.pop();
			}
		}
	}

	for (size_t i = 0; i < Result.size(); i++)
	{
		std::cout << Result[i] << " ";
	}
    
    return 0;
}