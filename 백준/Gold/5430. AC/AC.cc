#include <iostream>
#include <sstream>
#include <deque>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
    
    int T = 0; std::cin >> T;

    while (T--)
    {
        std::string P = ""; std::cin >> P;
        int N = 0; std::cin >> N;
        std::string NumList = ""; std::cin >> NumList;
        std::replace_if(NumList.begin(), NumList.end(), [](const char& C) { return !isdigit(C); }, ' ');
        
        std::deque<int> Array;
        std::string Temp = "";
        std::stringstream SS(NumList);
        while (SS >> Temp)
        {
            Array.push_back(std::stoi(Temp));
        }

        int RCount = 0;
        bool bError = false;
        for (char C : P)
        {
            if ('R' == C)
            {
                ++RCount;
            }
            else
            {
                if (Array.empty())
                {
                    bError = true;
                    break;
                }

                (0 != RCount % 2) ? Array.pop_back() : Array.pop_front();
            }
        }

        if (bError)
        {
            std::cout << "error\n";
        }
        else
        {
            std::cout << "[";

            if (RCount % 2)
            {
                for (int i = Array.size() - 1; i >= 0; --i)
                {
                    if (0 != i)
                    {
                        std::cout << Array[i] << ",";
                    }
                    else
                    {
                        std::cout << Array[i];
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
    }

    return 0;
}