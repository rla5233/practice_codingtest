#include <string>
#include <vector>

std::vector<int> solution(std::vector<int> Num_list, int N) 
{
    return std::vector<int>(Num_list.begin() + N - 1, Num_list.end());
}