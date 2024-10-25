#include <vector>

int solution(int N) 
{
    std::vector<int> Num(N, 0);
    for (int i = 0; i < static_cast<int>(Num.size()); ++i)
        Num[i] = i + 1;
    
    int Result = 0;
    int Sum = Num[0];
    int S = 0, E = 0;
    while (S <= E && E < Num.size())
    {
        if (N < Sum)
            Sum -= Num[S++];
        else if (N > Sum)
            Sum += Num[++E];
        else
        {
            ++Result;
            Sum -= Num[S++];
        }
    }
    
    return Result;
}