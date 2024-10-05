#include <string>

int solution(int N) 
{
	int Mul = 1, Piece = 6;
	while (0 != Piece % N)
	{
		Piece = 6 * ++Mul;
	}

    return Mul;
}