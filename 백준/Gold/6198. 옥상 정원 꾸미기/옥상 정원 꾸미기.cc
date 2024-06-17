#include <iostream>
#include <stack>

int main()
{
	int N = 0;
	std::cin >> N;

	unsigned int Sum = 0;
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
				Sum += static_cast<int>(Building.size());
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

				Sum += static_cast<int>(Building.size());
				Building.push(Height);
			}
		}
	}

	std::cout << Sum;
    
    return 0;
}