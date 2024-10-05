#include <string>

int solution(int Slice, int N) 
{
	return (N + Slice - 1) / Slice;
}