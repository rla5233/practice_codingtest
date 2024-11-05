#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> Arr1, vector<vector<int>> Arr2) 
{
    vector<vector<int>> Answer(Arr1.size(), vector<int>(Arr2[0].size(), 0));
    for (int i = 0; i < static_cast<int>(Answer.size()); ++i)
    {
        for (int j = 0; j < static_cast<int>(Answer[0].size()); ++j)
        {
            for (int k = 0; k < static_cast<int>(Arr1[i].size()); ++k)
            {
                Answer[i][j] += Arr1[i][k] * Arr2[k][j];
            }
        }
    }
    
    return Answer;
}