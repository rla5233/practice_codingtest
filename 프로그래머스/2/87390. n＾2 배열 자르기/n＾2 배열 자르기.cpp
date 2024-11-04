#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, long long Left, long long Right)
{
    vector<int> Answer; Answer.reserve(Right - Left + 1);
    for (long long i = Left; i <= Right; ++i)
        Answer.push_back(max(i / N, i % N) + 1);

    return Answer;
}