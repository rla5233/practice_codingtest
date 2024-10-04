#include <vector>
#include <algorithm>

int solution(std::vector<std::vector<int>> Sizes) 
{
    int W = 0, H = 0;
    for (int i = 0; i < static_cast<int>(Sizes.size()); ++i)
    {
        W = std::max(W, std::min(Sizes[i][0], Sizes[i][1]));
        H = std::max(H, std::max(Sizes[i][0], Sizes[i][1]));
    }

    return W * H;
}