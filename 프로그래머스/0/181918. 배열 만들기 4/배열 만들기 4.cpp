#include <string>
#include <vector>

std::vector<int> solution(std::vector<int> arr) 
{
    std::vector<int> stk;
    
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (stk.empty() || arr[i] > stk[stk.size() - 1])
        {
            stk.push_back(arr[i]);
        }
        else
        {
            stk.pop_back();
            --i;
        }
    }

    return stk;
}