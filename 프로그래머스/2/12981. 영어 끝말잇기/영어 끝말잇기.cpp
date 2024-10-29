#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(int N, vector<string> Words) 
{
    vector<int> Cnt(N, 0);
    unordered_set<string> S;
    S.insert(Words[0]);
    ++Cnt[0];

    char PrevLast = Words[0].back();
    for (int i = 1; i < Words.size(); ++i)
    {
        int Idx = i % N;
        ++Cnt[Idx];

        if (PrevLast != Words[i].front() || S.end() != S.find(Words[i]))
            return { Idx + 1, Cnt[Idx] };

        S.insert(Words[i]);
        PrevLast = Words[i].back();
    }

    return { 0, 0 };
}