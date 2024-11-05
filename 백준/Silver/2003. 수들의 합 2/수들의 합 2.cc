#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N = 0, M = 0; cin >> N >> M;
    vector<int> Nums(N, 0);
    for (int i = 0; i < N; i++)
        cin >> Nums[i];

    int Left = 0, Right = 0;
    int Answer = 0, Sum = 0;
    while (Right < N)
    {
        Sum += Nums[Right];

        while (M < Sum && Left <= Right)
            Sum -= Nums[Left++];

        Answer += (M == Sum);
        ++Right;
    }

    cout << Answer;
    return 0;
}