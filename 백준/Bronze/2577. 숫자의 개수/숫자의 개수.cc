#include <iostream>
#include <vector>

int main()
{
	int A = 0, B = 0, C = 0;
	std::cin >> A >> B >> C;

	int Mul = A * B * C;
	std::vector<int> NumVec(10, 0);
	while (0 != Mul)
	{
		int Number = Mul % 10;
		++NumVec[Number];
		Mul /= 10;
	}

	for (size_t i = 0; i < NumVec.size(); i++)
	{
		std::cout << NumVec[i] << std::endl;
	}
    
    return 0;
}