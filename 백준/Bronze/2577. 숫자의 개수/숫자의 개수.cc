#include <iostream>
using namespace std;

int A, B, C;
int num[10];

int main()
{
	cin >> A >> B >> C;

	int Data = A * B * C;

	while (Data != 0)
	{
		int inum = Data % 10;
		Data /= 10;

		num[inum]++;
	}

	for (int a : num)
	{
		cout << a << "\n";
	}
}