#include <vector>
#include <stack>

std::vector<int> solution(std::vector<int> Numbers) 
{
    std::vector<int> Result(Numbers.size(), -1);
    std::stack<std::pair<int, int>> S;
    for (int i = 0; i < Numbers.size(); ++i)
    {
        while (!S.empty() && S.top().first < Numbers[i])
        {
            Result[S.top().second] = Numbers[i];
            S.pop();
        }

        S.push({ Numbers[i], i });
    }
   
    return Result;
}