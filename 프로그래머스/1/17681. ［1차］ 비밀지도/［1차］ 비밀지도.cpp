#include <string>
#include <vector>

std::vector<std::string> solution(int N, std::vector<int> Arr1, std::vector<int> Arr2) 
{
    std::vector<std::string> Result(N, std::string(N, ' '));
    for (int i = 0; i < N; ++i)
    {
        int Num = Arr1[i] | Arr2[i];
        int Idx = N - 1;
        while (0 != Num)
        {
            if (1 == Num % 2) Result[i][Idx] = '#';
            Num >>= 1;
            --Idx;
        }
    }

    return Result;
}