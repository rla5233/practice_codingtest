#include <algorithm>
#include <string>
#include <vector>
#include <list>

using namespace std;

string ToUpperStr(const string& str)
{
    
}

int solution(int cacheSize, vector<string> cities) 
{
    list<string> LRU;
    
    int answer = 0;
    for (string& city : cities)
    {
        transform(city.begin(), city.end(), city.begin(), ::toupper);
        auto it = find(LRU.begin(), LRU.end(), city);
        if (it != LRU.end())
        {
            LRU.erase(it);
            ++answer;
        }
        else
        {
            if (cacheSize && cacheSize == LRU.size())
                LRU.pop_back();
            
            answer += 5;
        }
        
        if (cacheSize)
            LRU.push_front(city);
    }
    
    return answer;
}