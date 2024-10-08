#include <iostream>
#include <stack>

int main()
{
    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(0); std::cout.tie(0);

    std::string PL = "";
    std::cin >> PL;

    char Prev = ' ';
    int TotalScore = 0, Temp = 1, Div = 1;
    std::stack<char> S;
    for (char C : PL)
    {
        if ('[' == C || '(' == C)
        {
            if (']' == Prev || ')' == Prev)
            {
                TotalScore += Temp;
                ']' == Prev ? Temp /= Div : Temp /= Div;
                Div = 1;
            }
            
            '[' == C ? Temp *= 3 : Temp *= 2;

            Prev = C;
            S.push(C);
            continue;
        }

        if (']' == C && (S.empty() || '[' != S.top())
        ||  ')' == C && (S.empty() || '(' != S.top()))
        {
            TotalScore = 0;
            break;
        }
        else
        {
            ']' == C ? Div *= 3 : Div *= 2;
            Prev = C;
            S.pop();

            if (S.empty())
            {
                TotalScore += Temp;
                Temp = 1;
                Prev = ' ';
                Div = 1;
            }
        }
    }

    if (!S.empty())
    {
        TotalScore = 0;
    }

    std::cout << TotalScore;

    return 0;
}