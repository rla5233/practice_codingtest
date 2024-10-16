#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::vector<int> Tri(3, 0);
    std::cin >> Tri[0] >> Tri[1] >> Tri[2];

    std::sort(Tri.begin(), Tri.end());
    while (Tri[0] + Tri[1] <= Tri[2])
        --Tri[2];

    std::cout << std::accumulate(Tri.begin(), Tri.end(), 0);

    return 0;
}