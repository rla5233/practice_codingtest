#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {

    int r = num_list.size()/n;
    vector<vector<int>> answer(r,vector<int>(n));

    int ind = 0;
    for(int i =0; i < r; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            answer[i][j] = num_list[ind++];
        }
    }
    return answer;
}