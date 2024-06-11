#include <iostream>
#include <stack>

struct Top
{
	int Height = 0;
	int Idx = 0;
};

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
    
    int N = 0;
	std::cin >> N;
	
	std::stack<Top> Stack;
	for (int i = 1; i <= N; i++)
	{
		int H = 0;
		std::cin >> H;

		while (false == Stack.empty())
		{
			if (H < Stack.top().Height)
			{
				std::cout << Stack.top().Idx << " ";
				break;
			}
		
			Stack.pop();
		}

		if (true == Stack.empty())
		{
			std::cout << "0 ";
		}

		Stack.push(Top(H, i));
	}
    
    return 0;
}