#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string temp = "";
vector<bool> bUsed;
unordered_set<int> dupCheck;

bool isprime(int num)
{
    if (1 >= num) return false;
    
    for (int i = 2; i * i <= num; ++i)
        if (0 == num % i) return false;
    
    return true;
}

void findfunc(const string& numbers, int cnt, int& ans)
{
    if (temp.size() == cnt)
    {
        int num = stoi(temp);
        if (dupCheck.end() == dupCheck.find(num) && isprime(num))
            dupCheck.insert(num), ++ans; 

        return;
    }
    
    for (int i = 0; i < numbers.size(); ++i)
    {
        if (!bUsed[i])
        {
            temp.push_back(numbers[i]);
            bUsed[i] = true;
            findfunc(numbers, cnt, ans);
            temp.pop_back();
            bUsed[i] = false;
        }
    }
}

int solution(string numbers) 
{
    int answer = 0;
    bUsed.resize(numbers.size(), false);
    for (int i = 1; i <= numbers.size(); ++i)
        findfunc(numbers, i, answer);
    
    return answer;
}