#include <unordered_set>

int solution(int X, int Y, int N) 
{
    std::unordered_set<int> Nums;
    Nums.insert(Y);

    int Result = 0;
    while (!Nums.empty())
    {
        std::unordered_set<int> Temp;
        
        int Next = 0;
        for (int Num : Nums)
        {
            if (X > Num)
                continue;

            if (X == Num)
                return Result;

            Temp.insert(Num - N);

            if (!(Num & 1))
                Temp.insert(Num >> 1);

            if (0 == Num % 3)
                Temp.insert(Num / 3);
        }

        Nums.swap(Temp);
        ++Result;
    }

    return -1;
}