#include <iostream>
#include <stack>

int main()
{
    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(0); std::cout.tie(0);
    
    std::string Work = "";
    std::cin >> Work;

    int BarCount = 0;
    char Prev = ' ';
    std::stack<char> S;
    for (char C : Work)
    {
        if ('(' == C)
        {
            S.push(C);
        }
        else
        {
            S.pop();
            if ('(' == Prev)
            {
                BarCount += S.size();
            }
            else
            {
                ++BarCount;
            }
        }
        
        Prev = C;
    }
    
    std::cout << BarCount;

    return 0;
}