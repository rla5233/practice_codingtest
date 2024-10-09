#include <iostream>
#include <vector>
#include <stack>

int main()
{
    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(0); std::cout.tie(0);

    int N = 0;
    std::cin >> N;

    std::stack<std::pair<int, int>> S;
    std::vector<int> Result(N, -1); 
    for (int i = 0; i < N; ++i)
    {
        int Num = 0;
        std::cin >> Num;

        while (!S.empty() && S.top().first < Num)
        {
            Result[S.top().second] = Num;
            S.pop();
        }

        S.push({ Num, i });
    }

    for (int Num : Result)
    {
        std::cout << Num << " ";
    }

    return 0;
}