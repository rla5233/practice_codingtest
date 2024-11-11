#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N = 0; cin >> N;
    priority_queue<int, vector<int>, greater<int>> MinHeap;
    for (int i = 0; i < N * N; ++i)
    {
        int Num = 0; cin >> Num;

        if (N > MinHeap.size())
            MinHeap.push(Num);
        else if (Num > MinHeap.top())
        {
            MinHeap.pop();
            MinHeap.push(Num);
        }
    }

    cout << MinHeap.top();
    return 0;
}