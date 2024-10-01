#include <string>

int solution(int Number, int Limit, int Power) 
{
    int Result = 0;
    for (size_t i = 1; i <= Number; ++i)
    {
        int Count = 0;
        for (size_t j = 1; j * j <= i; ++j)
        {
            if (0 == i % j)
            {
                (i == j * j) ? Count += 1 : Count += 2;
            }
        }

        (Count > Limit) ? Result += Power : Result += Count;
    }

    return Result;
}