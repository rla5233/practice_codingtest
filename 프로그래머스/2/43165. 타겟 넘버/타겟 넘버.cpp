#include <string>
#include <vector>

using namespace std;

void DFS(const vector<int>& _Numbers, const int _Target, int& _Answer, int _Depth, int _Sum)
{
    if (_Numbers.size() == _Depth)
    {
        _Answer += (_Target == _Sum);
        return;
    }
    
    DFS(_Numbers, _Target, _Answer, _Depth + 1, _Sum + _Numbers[_Depth]);
    DFS(_Numbers, _Target, _Answer, _Depth + 1, _Sum - _Numbers[_Depth]);
}

int solution(vector<int> _Numbers, int _Target) 
{
    int Answer = 0;
    DFS(_Numbers, _Target, Answer, 0, 0);
    return Answer;
}