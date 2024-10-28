#include <vector>

using namespace std;

vector<int> solution(int Brown, int Yellow) 
{
    long Size = Brown + Yellow;
    vector<pair<int, int>> AllPair;
    for (long i = 1; i * i <= Size; ++i)
    {
        if (0 == Size % i)
            AllPair.push_back({ Size / i, i });
    }

    vector<int> Result;
    for (const auto& Pair : AllPair)
    {
        int X = Pair.first, Y = Pair.second;
        if (2 * X + 2 * Y - 4 == Brown && (X - 2) * (Y - 2) == Yellow)
        {
            Result.push_back(X);
            Result.push_back(Y);
            break;
        }
    }

    return Result;
}