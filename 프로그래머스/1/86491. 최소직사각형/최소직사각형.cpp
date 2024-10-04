#include <vector>
#include <algorithm>

int solution(std::vector<std::vector<int>> Sizes) 
{
    for (int i = 0; i < Sizes.size(); ++i)
    {
        if (Sizes[i][0] < Sizes[i][1])
        {
            std::swap(Sizes[i][0], Sizes[i][1]);
        }
    }
    
    std::sort(Sizes.begin(), Sizes.end());
    int W = Sizes.back().front(), H = 0;

    for (int i = 0; i < Sizes.size() - 1; ++i)
    {
        if (Sizes[i][0] < Sizes[i][1])
        {
            std::swap(Sizes[i][0], Sizes[i][1]);
        }
    }

    for (int i = 0; i < Sizes.size(); ++i)
    {
        if (H < Sizes[i][1])
        {
            H = Sizes[i][1];
        }
    }

    return W * H;
}