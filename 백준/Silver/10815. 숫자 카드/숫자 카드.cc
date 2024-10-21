#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(0); std::cout.tie(0);

    int N = 0; std::cin >> N;
    std::vector<int> v;
    while (N--)
    {
        int Num = 0; std::cin >> Num;
        v.push_back(Num);
    }
    
    std::sort(v.begin(), v.end());
    int M = 0; std::cin >> M;
    while (M--)
    {
        int Num = 0; std::cin >> Num;
        std::cout << std::binary_search(v.begin(), v.end(), Num) << " ";
    }

    return 0;
}