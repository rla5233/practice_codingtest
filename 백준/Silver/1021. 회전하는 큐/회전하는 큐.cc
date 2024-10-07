#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int N = 0, M = 0;
    std::cin >> N >> M;

    int Result = 0;
    std::vector<int> dq(N, 0);
    std::vector<int>::iterator it = dq.begin();
    std::iota(dq.begin(), dq.end(), 1);
    while (M--)
    {
        int Out = 0;
        std::cin >> Out;

        std::vector<int>::iterator Findit = std::find(dq.begin(), dq.end(), Out);
        int Dist1 = std::abs(std::distance(it, Findit));
        int Dist2 = std::distance(dq.begin(), it) + std::distance(Findit, dq.end());
        int Dist3 = std::distance(dq.begin(), Findit) + std::distance(it, dq.end());
        Result += std::min(std::min(Dist1, Dist2), Dist3);
        it = dq.erase(Findit);
    }

    std::cout << Result;

    return 0;
}