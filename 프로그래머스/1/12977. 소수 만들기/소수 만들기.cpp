#include <vector>
#include <iostream>

int solution(std::vector<int> Nums) 
{
    int Result = 0;
    for (int i = 0; i < Nums.size() - 2; ++i)
    {
        for (int j = i + 1; j < Nums.size() - 1; ++j)
        {
            for (int k = j + 1; k < Nums.size(); ++k)
            {
                ++Result;
                int Num = Nums[i] + Nums[j] + Nums[k];
                for (int i = 2; i * i <= Num; i++)
                {
                    if (0 == Num % i)
                    {
                        --Result;
                        break;
                    }
                }
            }
        }
    }

    return Result;
}