#include <iostream>
#include <vector>

using namespace std;

long long Fibo(int N, int& Cnt)
{
    if (1 == N || 2 == N)
    {
        ++Cnt;
        return 1;
    }
    
    return Fibo(N - 2, Cnt) + Fibo(N - 1, Cnt);
}

long long FiboDP(int N, int& Cnt)
{
    vector<int> Nums(N + 1, -1);
    for (int i = 3; i <= N; ++i)
    {
        ++Cnt;
        Nums[i] = Nums[i - 2] + Nums[i - 1];
    }
    
    return Nums[N];
}

int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int N = 0; cin >> N;
    int Cnt1 = 0, Cnt2 = 0;

    Fibo(N, Cnt1);
    FiboDP(N, Cnt2);
    cout << Cnt1 << " " << Cnt2;

    return 0;
}