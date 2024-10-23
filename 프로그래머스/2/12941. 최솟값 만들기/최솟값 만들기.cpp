#include <vector>
#include <algorithm>

int solution(std::vector<int> A, std::vector<int> B)
{
    std::sort(A.begin(), A.end());
    std::sort(B.rbegin(), B.rend());
    
    int Result = 0;
    for (int i = 0; i < A.size(); ++i)
        Result += A[i] * B[i];

    return Result;
}