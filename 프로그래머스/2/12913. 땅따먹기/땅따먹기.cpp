#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int>> land)
{
    for (int i = 1; i < static_cast<int>(land.size()); ++i)
    {
        land[i][0] += max(land[i - 1][1], max(land[i - 1][2], land[i - 1][3]));
        land[i][1] += max(land[i - 1][0], max(land[i - 1][2], land[i - 1][3]));
        land[i][2] += max(land[i - 1][0], max(land[i - 1][1], land[i - 1][3]));
        land[i][3] += max(land[i - 1][0], max(land[i - 1][1], land[i - 1][2]));
    }

    return *max_element(land.back().begin(), land.back().end());
}