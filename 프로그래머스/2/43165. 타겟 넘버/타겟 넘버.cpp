#include <string>
#include <vector>

using namespace std;

void FindFunc(const vector<int>& _Numbers, const int _Target, int& _Answer, int _Sum, int _Idx)
{
    if (_Numbers.size() == _Idx)
    {
        _Answer += (_Target == _Sum);
        return;
    }
        
    for (int Oper = 0; Oper <= 1; ++Oper)
    {
        if(Oper)
        {
            _Sum += _Numbers[_Idx];
            FindFunc(_Numbers, _Target, _Answer, _Sum, _Idx + 1);
            _Sum -= _Numbers[_Idx];
        }
        else
        {
            _Sum -= _Numbers[_Idx];
             FindFunc(_Numbers, _Target, _Answer, _Sum, _Idx + 1);
            _Sum += _Numbers[_Idx];
        }
    }
}

int solution(vector<int> _Numbers, int _Target) 
{
    int Answer = 0;
    FindFunc(_Numbers, _Target, Answer, 0, 0);
    return Answer;
}