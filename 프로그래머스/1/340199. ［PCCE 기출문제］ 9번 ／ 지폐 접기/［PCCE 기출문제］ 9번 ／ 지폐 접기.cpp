#include <vector>
#include <algorithm>

int solution(std::vector<int> Wallet, std::vector<int> Bill) 
{
    int Result = 0;

    int Min_B = *std::min_element(Bill.begin(), Bill.end());
    int Max_B = *std::max_element(Bill.begin(), Bill.end());

    int Min_W = *std::min_element(Wallet.begin(), Wallet.end());
    int Max_W = *std::max_element(Wallet.begin(), Wallet.end());

    while (Min_B > Min_W || Max_B > Max_W)
    {
        Max_B >>= 1;
        if (Min_B > Max_B)
        {
            int Temp = Max_B;
            Max_B = Min_B;
            Min_B = Temp;
        }

        ++Result;
    }

    return Result;
}