#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& num1, const string& num2)
{
    return num1 + num2 > num2 + num1;
}

string solution(vector<int> numbers) 
{
    vector<string> temp;
    for (int num : numbers)
        temp.push_back(to_string(num));
    
    stable_sort(temp.begin(), temp.end(), cmp);
    
    if ("0" == temp.front())
        return "0";
    
    string answer = "";
    for (const string& num : temp)
         answer += num;
       
    
    return answer;
}