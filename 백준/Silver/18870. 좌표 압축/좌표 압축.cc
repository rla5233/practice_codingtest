#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

int main()
{
    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(0); std::cout.tie(0);
    
    int N = 0;
    std::cin >> N;

    std::unordered_map<int, int> Mem;
    std::vector<int> Num, Temp;
    while (N--)
    {
        int X = 0;
        std::cin >> X;
        Num.push_back(X);

        if (Mem.insert({ X, 0 }).second)
            Temp.push_back(X);
    }

    std::sort(Temp.begin(), Temp.end());
    for (int i = 0; i < Temp.size(); ++i)
        Mem[Temp[i]] = i;

    for (int N : Num)
        std::cout << Mem[N] << " ";

    return 0;
}