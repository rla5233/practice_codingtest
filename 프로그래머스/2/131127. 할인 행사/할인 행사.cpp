#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> Want, vector<int> Number, vector<string> Discount) 
{
    unordered_map<string, int> Cnt;
    for (int i = 0; i < 9; ++i)
        ++Cnt[Discount[i]];

    int Answer = 0;   
    for (int i = 9; i < static_cast<int>(Discount.size()); ++i)
    {
        bool bFlag = true;
        ++Cnt[Discount[i]];
        for (int j = 0; j < static_cast<int>(Want.size()); ++j)
        {
            if (Cnt[Want[j]] < Number[j])
            {
                bFlag = false;
                break;
            }
        }
        
        Answer += bFlag;
        --Cnt[Discount[i - 9]];
    }
 
    return Answer;
}