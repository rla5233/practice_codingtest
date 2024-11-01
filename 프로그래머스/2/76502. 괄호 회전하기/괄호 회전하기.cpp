#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

int solution(string S) 
{
    int N = S.size();
    string Temp = S + S;
    unordered_map<char, char> Par = { { ')', '(' }, { ']', '[' }, { '}', '{' } };
    
    int Result = 0;
    for (int i = 0; i < N; ++i)
    {
        stack<char> Stack;
        bool bBreak = false;
        for (int j = i; j < N + i; ++j)
        {
            if (Par.end() != Par.find(Temp[j]))
            {
                if (!Stack.empty() && Par[Temp[j]] == Stack.top())
                    Stack.pop();
                else
                {
                    bBreak = true;
                    break;                    
                }
            }
            else
                Stack.push(Temp[j]);
        }
        
        !bBreak && Stack.empty() ? ++Result : Result;
    }
    
    return Result;
}