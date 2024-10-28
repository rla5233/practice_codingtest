#include <string>
#include <stack>

using namespace std;

int solution(string S)
{
    stack<char> Stack;
    for (char C : S)
    {
        if (!Stack.empty() && Stack.top() == C)
            Stack.pop();
        else
            Stack.push(C);
    }

    return Stack.empty();
}