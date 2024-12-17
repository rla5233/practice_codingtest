#include <string>
#include <stack>

bool solution(std::string s)
{
    std::stack<char> Stack;
    for (char c : s)
    {
        if ('(' == c)
            Stack.push(c);
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