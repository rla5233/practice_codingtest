#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int N = 0; cin >> N;
    vector<int> Inter;
    Inter.reserve(N - 1);

    int GCD = 0, Prev = 0; cin >> Prev;
    for (int i = 1; i < N; ++i)
    {
        int Cur = 0; cin >> Cur;
        int Diff = Cur - Prev;
        Inter.push_back(Diff);
        Prev = Cur;

        if (1 == i)
            GCD = Inter.front();
        else if (1 < i)
            GCD = gcd(GCD, Diff);
    }

    int Result = 0;
    for (int Cur : Inter)
        Result += (Cur / GCD) - 1;

    cout << Result;
    return 0;
}