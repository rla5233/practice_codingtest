#include <vector>
#include <numeric>

std::vector<int> solution(std::vector<int> Sequence, int K)
{
    std::vector<int> Result(2, 0);

    int S = 0, E = 0;
    int Sum = Sequence[0];
    int Len = Sequence.size() + 1;
    while (S <= E && E < Sequence.size())
    {
        if (K < Sum)
            Sum -= Sequence[S++];
        else if (K > Sum)
            Sum += Sequence[++E];
        else
        {
            if (Len > E - S + 1)
            {
                Result[0] = S;
                Result[1] = E;
                Len = E - S + 1;
            }

            Sum -= Sequence[S++];
        }
    }

    return Result;
}