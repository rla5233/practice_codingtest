#include <iostream>
#include <stack>

int main()
{
    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(0); std::cout.tie(0);

    int N = 0;
    std::cin >> N;

    size_t Result = 0;
    std::stack<std::pair<int, int>> S;
    while (N--)
    {
        int Num = 0;
        std::cin >> Num;

        if (S.empty())
        {
            S.push({ Num, 1 });
        }
        else
        {
            if (S.top().first > Num)
            {
                ++Result;
                S.push({ Num, 1 });
            }
            else if (S.top().first == Num)
            {
                Result += S.top().second;
                if (2 <= S.size())
                {
                    ++Result;
                }
                ++S.top().second;
            }
            else
            {
                while (!S.empty() && S.top().first < Num)
                {
                    Result += S.top().second;
                    S.pop();
                }

                if (S.empty())
                {
                    S.push({ Num, 1 });
                }
                else if (S.top().first == Num)
                {
                    Result += S.top().second;
                    if (2 <= S.size())
                    {
                        ++Result;
                    }
                    ++S.top().second;
                }
                else
                {
                    ++Result;
                    S.push({ Num, 1 });
                }
            }
        }
    }

    std::cout << Result;

    return 0;
}