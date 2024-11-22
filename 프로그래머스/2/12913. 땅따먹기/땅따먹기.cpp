#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int>> land)
{
    vector<int> prevNum(4, 0);
    for (int i = 0; i < 4; ++i)
        prevNum[i] = land[0][i];

    for (int i = 1; i < static_cast<int>(land.size()); ++i)
    {
        vector<int> curNum(4, 0);
        for (int j = 0; j < static_cast<int>(land[i].size()); ++j)
        {
            curNum[j] = land[i][j] + max
            ({ 
                j != 0 ? prevNum[0] : 0,
                j != 1 ? prevNum[1] : 0,
                j != 2 ? prevNum[2] : 0,
                j != 3 ? prevNum[3] : 0
            });
        }

        prevNum = curNum;
    }

    return *max_element(prevNum.begin(), prevNum.end());
}