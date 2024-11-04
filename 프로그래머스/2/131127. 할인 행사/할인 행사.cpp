#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> Want, vector<int> Number, vector<string> Discount) 
{
    unordered_map<string, int> Cnt;
    for (int i = 0; i < static_cast<int>(Want.size()); ++i)
        Cnt[Want[i]] = Number[i];
    
    int WantCnt = Cnt.size();
    for (int i = 0; i < 10; ++i)
    {
        if(Cnt.end() != Cnt.find(Discount[i]))
        {
            --Cnt[Discount[i]];
            if (0 == Cnt[Discount[i]])
                --WantCnt;
        }
    }
    
    int Answer = (0 == WantCnt);
    for (int i = 10; i < static_cast<int>(Discount.size()); ++i)
    {
        if (Cnt.end() != Cnt.find(Discount[i]))
        {
            --Cnt[Discount[i]];
            if (0 == Cnt[Discount[i]])
                --WantCnt;
        }
        
        if (Cnt.end() != Cnt.find(Discount[i - 10]))
        {
            ++Cnt[Discount[i - 10]];
            if (1 == Cnt[Discount[i - 10]])
                ++WantCnt;
        }
        
        Answer += (0 == WantCnt);
    }
    
    return Answer;
}