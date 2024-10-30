#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int solution(int K, vector<int> Tangerine) 
{
    unordered_map<int, int> Cnt;
    for (int Size : Tangerine)
        ++Cnt[Size];
    
    priority_queue<int> Sort;
    for (const auto& Max : Cnt)
        Sort.push(Max.second);
    
    int Result = 0; 
    while (!Sort.empty())
    {
        ++Result;
        K -= Sort.top();
        Sort.pop();
        
        if(0 >= K)
            break;
    }
    
    return Result;
}