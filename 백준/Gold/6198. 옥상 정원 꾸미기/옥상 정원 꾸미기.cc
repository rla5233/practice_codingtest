#include <iostream>
#include <stack>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
    
	int N = 0;
	std::cin >> N;

	size_t Sum = 0;
	std::stack<int> Building;
	for (int i = 0; i < N; i++)
	{
		int Height = 0;
		std::cin >> Height;

		if (true == Building.empty())
		{
			Building.push(Height);
		}
		else
		{
			if (Building.top() > Height)
			{
				Sum += Building.size();
				Building.push(Height);
			}
			else
			{
				while (Building.top() <= Height)
				{
					Building.pop();

					if (true == Building.empty())
					{
						break;
					}
				}

				Sum += Building.size();
				Building.push(Height);
			}
		}
	}

	std::cout << Sum;
    
    return 0;
}