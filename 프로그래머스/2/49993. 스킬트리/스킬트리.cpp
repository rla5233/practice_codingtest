#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) 
{
    vector<bool> bskill(26, false);
    for (char c : skill)
        bskill[c - 'A'] = true;
    
    int answer = static_cast<int>(skill_trees.size());
    for (const auto& str : skill_trees)
    {
        int idx = 0;
        for (char c : str)
        {
            if (bskill[c - 'A'])
            {
                if (skill[idx++] != c)
                {
                    --answer;
                    break;
                }
            }
        }
    }
    
    return answer;
}