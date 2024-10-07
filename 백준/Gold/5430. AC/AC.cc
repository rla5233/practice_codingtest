#include <iostream>
#include <deque>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
    
    int T = 0; std::cin >> T;
    while (T--)
    {
        std::string P = ""; std::cin >> P;
        int N = 0; std::cin >> N;
        std::string NumList = ""; std::cin >> NumList;
        
        std::deque<int> Array;
        std::string Temp = "";
        for (char C : NumList)
        {
            if (isdigit(C))
            {
                Temp.push_back(C);
                continue;
            }

            if (!Temp.empty())
            {
                Array.push_back(std::stoi(Temp));
                Temp = "";
            }
        }

        bool bError = false, bReverse = false;
        for (char C : P)
        {
            if ('R' == C)
            {
                bReverse = !bReverse;
                continue;
            }

            if (Array.empty())
            {
                bError = true;
                break;
            }

            bReverse ? Array.pop_back() : Array.pop_front();
        }

        if (bError)
        {
            std::cout << "error\n";
            continue;
        }
         
        std::cout << "[";
        if (bReverse)
        {
            for (int i = Array.size() - 1; i >= 0; --i)
            {
                std::cout << Array[i];
                if (0 != i)
                {
                    std::cout << ",";
                }
            }
        }
        else
        {
            for (int i = 0; i < Array.size(); ++i)
            {
                if (Array.size() - 1 != i)
                {
                    std::cout << Array[i] << ",";
                }
                else
                {
                    std::cout << Array[i];
                }
            }
        }
        std::cout << "]\n";
    }

    return 0;
}