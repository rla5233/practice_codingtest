#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> _Clothes) 
{
    unordered_map<string, int> AllCnt;
    for (const auto& Cloth : _Clothes)
        ++AllCnt[Cloth.back()];

    int Answer = 1;
    for (const auto& CurCnt : AllCnt)    
        Answer *= (CurCnt.second + 1);
    
    return Answer - 1;
}