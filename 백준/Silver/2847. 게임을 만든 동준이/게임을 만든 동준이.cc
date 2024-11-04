#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int N = 0; cin >> N;
    vector<int> Score(N, 0);
    for (int i = 0; i < N; ++i)
        cin >> Score[i];

    int Result = 0;
    for (int i = N - 1; i > 0; --i)
    {
        if (Score[i] <= Score[i - 1])
        {
            int Diff = Score[i - 1] - Score[i] + 1;
            Result += Diff; Score[i - 1] -= Diff;
        }
    }

    cout << Result;
    return 0;
}