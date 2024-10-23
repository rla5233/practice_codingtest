#include <unordered_set>

int solution(int X, int Y, int N) 
{
    if (X == Y)
        return 0;
    
    std::unordered_set<int> Nums;
    Nums.insert(X);

    int Result = 0;
    while (!Nums.empty())
    {
        ++Result;

        int Next = 0;
        std::unordered_set<int> Temp;
        for (int Num : Nums)
        {
            Next = Num + N;
            if (Y > Next)
                Temp.insert(Next);
            else if (Y == Next)
                return Result;

            Next = Num << 1;
            if (Y > Next)
                Temp.insert(Next);
            else if (Y == Next)
                return Result;

            Next = 3 * Num;
            if (Y > Next)
                Temp.insert(Next);
            else if (Y == Next)
                return Result;
        }

        Nums.swap(Temp);
    }

    return -1;
}