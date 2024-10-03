#include <vector>
#include <map>

std::vector<int> solution(std::vector<int> Emergency) 
{
    std::map<int, int> Sort;
    for (int E : Emergency)
    {
        Sort[E] = 0;
    }

    int Order = static_cast<int>(Sort.size());
    for (std::pair<const int, int>& E : Sort)
    {
        E.second = Order--;
    }

    for (int& E : Emergency)
    {
        E = Sort[E];
    }

    return Emergency;
}