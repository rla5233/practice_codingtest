#include <string>
#include <vector>

using namespace std;

void DFS(const vector<int>& _Numbers, const int _Target, int& _Answer, int _Sum, int _Idx)
{
    if (_Numbers.size() == _Idx)
    {
        _Answer += (_Target == _Sum);
        return;
    }
    
    DFS(_Numbers, _Target, _Answer, _Sum + _Numbers[_Idx], _Idx + 1);
    DFS(_Numbers, _Target, _Answer, _Sum - _Numbers[_Idx], _Idx + 1);
}

int solution(vector<int> _Numbers, int _Target) 
{
    int Answer = 0;
    DFS(_Numbers, _Target, Answer, 0, 0);
    return Answer;
}