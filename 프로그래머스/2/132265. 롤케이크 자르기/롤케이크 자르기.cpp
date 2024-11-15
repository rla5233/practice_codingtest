#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> _Topping) 
{
    unordered_map<int, int> Left, Right;
    for (int E : _Topping)
        ++Right[E];
    
    int Answer = 0;
    for (int E : _Topping)
    {
        ++Left[E]; --Right[E];
        if (0 == Right[E])
            Right.erase(Right.find(E));
        
        if (Left.size() == Right.size())
            ++Answer;
    }

    return Answer;
}