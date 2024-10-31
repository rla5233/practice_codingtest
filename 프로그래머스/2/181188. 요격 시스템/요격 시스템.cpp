#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool Cmp(const vector<int>& A, const vector<int>& B)
{
    return A.front() < B.front();    
}

int solution(vector<vector<int>> Targets) 
{
    // 미사일을 최소로 사용해서 모든 폭격 미사일을 요격하려 합니다.
    
    // A 나라가 발사한 폭격 미사일은 x 축에 평행한 직선 형태의 모양 (s, e)
    // B 나라는 특정 x 좌표에서 y 축에 수평이 되도록 미사일을 발사하며, 발사된 미사일은 해당 x 좌표에 걸쳐있는 모든 폭격 미사일을 관통하여 한 번에 요격할 수 있습니다.
    // s와 e에서 발사하는 요격 미사일로는 요격할 수 없습니다.
    // 요격 미사일은 실수인 x 좌표에서도 발사할 수 있습니다.
    
    sort(Targets.begin(), Targets.end(), Cmp);
    
    int Result = 1, E = INT32_MAX;
    for(const auto& Target : Targets)
    {
        if (E <= Target[0])
        {
            ++Result;
            E = Target[1];
        }
        
        if (E > Target[1])
            E = Target[1];
    }
    
    return Result;
}