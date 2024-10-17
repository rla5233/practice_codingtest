#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(0); std::cout.tie(0);
    
    int N = 0, k = 0;
    std::cin >> N >> k;

    std::vector<int> v;
    while (N--)
    {
        int Score = 0;
        std::cin >> Score;
        v.push_back(Score);
    }

    std::sort(v.rbegin(), v.rend());
    std::cout << v[k - 1];

    return 0;
}