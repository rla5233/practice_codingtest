#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(0); std::cout.tie(0);
    
    int N = 0; std::cin >> N;

    std::vector<std::pair<int, int>> Num;
    
    for (int i = 0; i < N; ++i)
    {
        int X = 0; std::cin >> X;
        Num.push_back({ X, i });
    }

    std::sort(Num.begin(), Num.end());
    
    int Prev = Num[0].first;
    Num[0].first = 0;
    for (int i = 1; i < Num.size(); ++i)
    {
        int Cur = Num[i].first;
        if (Prev != Cur)
            Num[i].first = Num[i - 1].first + 1;
        else
            Num[i].first = Num[i - 1].first;
        
        Prev = Cur;
    }

    std::sort(Num.begin(), Num.end(), [&](const std::pair<int, int>& A, const std::pair<int, int>& B)
        {
            return A.second < B.second;
        }
    );

    for (const auto& Pair : Num)
        std::cout << Pair.first << " ";

    return 0;
}