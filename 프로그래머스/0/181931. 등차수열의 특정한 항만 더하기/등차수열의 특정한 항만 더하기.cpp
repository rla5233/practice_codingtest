#include <string>
#include <vector>
#include <functional>

int solution(int A, int D, std::vector<bool> Included)
{
    int Answer = 0;

    std::function<int(int N)> Sequence = [&](int N)->int
        {
            return A + (D * N);
        };

    for (int i = 0; i < Included.size(); ++i)
    {
        if (true == Included[i])
        {
            Answer += Sequence(i);
        }
    }

    return Answer;
}