#include <vector>

int solution(std::vector<int> A, std::vector<int> B) 
{
    int Result = 0;
    for (int i = 0; i < static_cast<int>(A.size()); ++i)
    {
        Result += A[i] * B[i];
    }

    return Result;
}