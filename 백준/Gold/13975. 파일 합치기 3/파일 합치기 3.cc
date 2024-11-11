#include <iostream>
#include <queue>

using namespace std;
using int64 = long long;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T = 0; cin >> T;
    while (T--)
    {
        priority_queue<int64, vector<int64>, greater<int64>> AllSize;
        
        int K = 0; cin >> K;
        while (K--)
        {
            int64 Size = 0; cin >> Size;
            AllSize.push(Size);
        }

        int64 Count = 0;
        while (1 < AllSize.size())
        {
            int64 Size1 = AllSize.top(); AllSize.pop();
            int64 Size2 = AllSize.top(); AllSize.pop();
            
            int64 Sum = Size1 + Size2;
            AllSize.push(Sum);
            Count += Sum;
        }

        cout << Count << '\n';
    }
    
    return 0;
}