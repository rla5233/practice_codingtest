#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

int solution(int A, int B, int C, int D) 
{
    std::vector<int> Table(6, 0);
    ++Table[A - 1]; ++Table[B - 1]; ++Table[C - 1]; ++Table[D - 1];
    std::vector<std::vector<int>> Nums(5);

    for (int i = 0; i < static_cast<int>(Table.size()); ++i)
    {
        Nums[Table[i]].push_back(i + 1);
    }

    if (!Nums[4].empty())
    {
        return 1111 * Nums[4][0];
    }
    else if (!Nums[3].empty())
    {
        return static_cast<int>(pow(10 * Nums[3][0] + Nums[1][0], 2));
    }
    else if (Nums[2].size() == 2)
    {
        return (Nums[2][0] + Nums[2][1]) * abs(Nums[2][0] - Nums[2][1]);
    }
    else if (Nums[2].size() == 1)
    {
        return Nums[1][0] * Nums[1][1];
    }
    else
    {
        return *std::min_element(Nums[1].begin(), Nums[1].end());
    }
}