#include <vector>
#include <algorithm>

int solution(std::vector<int> Array) 
{
    std::sort(Array.begin(), Array.end());
    return Array[Array.size() / 2];
}
