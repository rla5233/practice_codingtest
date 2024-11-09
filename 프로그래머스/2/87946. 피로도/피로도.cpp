#include <string>
#include <vector>

using namespace std;

void FindFunc(const vector<vector<int>>& _Dungeons, vector<bool>& _bUsed, int _K, int _Count, int& _Answer)
{
    _Answer = max(_Count, _Answer);

    for (int i = 0; i < static_cast<int>(_Dungeons.size()); ++i)
    {
        if (!_bUsed[i] && _K >= _Dungeons[i].front())
        {
            _bUsed[i] = true;
            FindFunc(_Dungeons, _bUsed, _K - _Dungeons[i].back(), _Count + 1, _Answer);
            _bUsed[i] = false;
        }
    }
}

int solution(int _K, vector<vector<int>> _Dungeons)
{
    vector<bool> bUsed(_Dungeons.size(), false);
    
    int Answer = 0;
    FindFunc(_Dungeons, bUsed, _K, 0, Answer);
    return Answer;
}