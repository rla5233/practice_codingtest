#include <string>
#include <stack>

bool solution(std::string S)
{
    std::stack<char> Stack;
    for (char C : S)
    {
        if ('(' == C)
            Stack.push(C);
        else
        {
            if (Stack.empty())
                return false;
            else
                Stack.pop();
        }
    }

    return Stack.empty();
}