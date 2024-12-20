#include <vector>

using namespace std;

vector<int> solution(int Brown, int Yellow) 
{
    int Size = Brown + Yellow;
    vector<int> Result;
    for (int i = 1; i * i <= Size; ++i)
    {
        if (0 == Size % i)
        {
            int X = Size / i, Y = i;
            if (2 * X + 2 * Y - 4 == Brown && (X - 2) * (Y - 2) == Yellow)
            {
                Result.push_back(X);
                Result.push_back(Y);
                break;
            }
        }
    }

    return Result;
}