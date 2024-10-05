#include <numeric>
#include <vector>

double solution(std::vector<int> Numbers) 
{
    return static_cast<double>(std::accumulate(Numbers.begin(), Numbers.end(), 0)) / Numbers.size();
}