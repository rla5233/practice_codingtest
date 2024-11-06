#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N = 0, M = 0; cin >> N >> M;
    vector<string> DNA(N, "");
    for (int i = 0; i < N; ++i)
        cin >> DNA[i];

    string AnsDNA = "";
    int AnsDistance = 0;
    unordered_map<char, int> Cnt;
    for (int i = 0; i < M; ++i)
    {
        pair<int, char> Max = { 0, ' ' };
        for (int j = 0; j < N; ++j)
        {
            char CurN = DNA[j][i];
            ++Cnt[CurN];
            if (Max.first < Cnt[CurN])
            {
                Max.first = Cnt[CurN];
                Max.second = CurN;
            }
            else if (Max.first == Cnt[CurN])
            {
                if (Max.second > CurN)
                    Max.second = CurN;
            }
        }

        AnsDistance += N - Max.first;
        AnsDNA += Max.second;
        Cnt.clear();
    }

    cout << AnsDNA << '\n' << AnsDistance;
    return 0;
}