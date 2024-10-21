#include <iostream>
#include <unordered_set>

int main()
{
    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(0); std::cout.tie(0);

    int N = 0; std::cin >> N;
    std::unordered_set<int> US;
    while (N--)
    {
        int Num = 0; std::cin >> Num;
        US.insert(Num);
    }

    int M = 0; std::cin >> M;
    while (M--)
    {
        int Num = 0; std::cin >> Num;
        std::cout << US.contains(Num) << " ";
    }

    return 0;
}