#include <algorithm>
#include <vector>

using namespace std;

bool Cmp(const vector<int>& A, const vector<int>& B)
{
    return A.back() < B.back();    
}

int solution(vector<vector<int>> Targets) 
{
    sort(Targets.begin(), Targets.end(), Cmp);
    
    int Result = 0, E = -1;
    for(const auto& Target : Targets)
    {
        if (E <= Target[0])
        {
            E = Target[1];
            ++Result;
        }
    }
    
    return Result;
}