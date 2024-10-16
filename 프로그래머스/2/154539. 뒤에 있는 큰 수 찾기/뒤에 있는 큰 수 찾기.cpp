#include <vector>
#include <stack>

std::vector<int> solution(std::vector<int> Numbers) 
{
    std::vector<int> Result(Numbers.size(), -1);
    std::stack<int> S;
    for (int i = 0; i < Numbers.size(); ++i)
    {
        while (!S.empty() && Numbers[S.top()] < Numbers[i])
        {
            Result[S.top()] = Numbers[i];
            S.pop();
        }

        S.push(i);
    }
   
    return Result;
}