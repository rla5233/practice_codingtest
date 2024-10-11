#include <string>
#include <vector>

void MakeSecretMap(std::vector<std::string>& Map, int MapIndex, int Num)
{
    int Idx = Map.size() - 1;
    while (0 != Num)
    {
        if (1 == Num % 2)  Map[MapIndex][Idx] = '#';
        Num >>= 1;
        --Idx;
    }
}

std::vector<std::string> solution(int N, std::vector<int> Arr1, std::vector<int> Arr2) 
{
    std::vector<std::string> Result(N, std::string(N, ' '));

    for (int i = 0; i < N; ++i)
    {
        MakeSecretMap(Result, i, Arr1[i]);
        MakeSecretMap(Result, i, Arr2[i]);
    }

    return Result;
}