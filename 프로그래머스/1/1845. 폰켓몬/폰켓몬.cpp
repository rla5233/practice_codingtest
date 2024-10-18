#include <vector>
#include <unordered_set>

int solution(std::vector<int> Nums)
{
    std::unordered_set<int> S;
    for (int Num : Nums)
        S.insert(Num);

    return S.size() > Nums.size() / 2 ? Nums.size() / 2 : S.size();
}