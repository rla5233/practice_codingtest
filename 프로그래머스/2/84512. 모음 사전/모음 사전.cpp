#include <algorithm>
#include <string>
#include <vector>
#include <set>


using namespace std;

const string vowel = "AEIOU";

void MakeDic(set<string>& dic, string word, int k)
{
    if (vowel.size() == k)
    {   
        if (!word.empty())
            dic.insert(word);

        return;
    }
    
    MakeDic(dic, word, k + 1);
    
    for (int i = 0; i < static_cast<int>(vowel.size()); ++i)
        MakeDic(dic, word + vowel[i], k + 1);
}

int solution(string word)
{
    set<string> dic;
    MakeDic(dic, "", 0);
    return distance(dic.begin(), dic.find(word)) + 1;
}