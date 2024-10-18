#include <vector>
#include <unordered_set>

int solution(std::vector<int> Nums)
{
    std::unordered_set<int> S(Nums.begin(), Nums.end());
    return std::min(S.size(), Nums.size() / 2);
}