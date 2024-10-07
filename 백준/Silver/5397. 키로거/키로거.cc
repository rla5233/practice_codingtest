#include <iostream>
#include <list>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int T = 0;
    std::cin >> T;

    while (T--)
    {
        std::string Input = "";
        std::cin >> Input;

        std::list<char> L, R;
        for (char C : Input)
        {
            if ('<' == C)
            {
                if (!L.empty())
                {
                    R.push_front(L.back());
                    L.pop_back();

                }
            }
            else if ('>' == C)
            {
                if (!R.empty())
                {
                    L.push_back(R.front());
                    R.pop_front();
                }

            }
            else if ('-' == C)
            {
                if (!L.empty())
                {
                     L.pop_back();
                }
            }
            else
            {
                L.push_back(C);
            }
        }

        for (char C : L)
        {
            std::cout << C;
        }

        for (char C : R)
        {
            std::cout << C;
        }

        std::cout << '\n';
    }

    return 0;
}