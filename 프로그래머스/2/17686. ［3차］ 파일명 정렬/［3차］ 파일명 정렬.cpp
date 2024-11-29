#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void FindHeadNum(const string& str, string& head, int& num)
{
    int idx = 0;
    while (idx < str.size() && !isdigit(str[idx]))
        head.push_back(toupper(str[idx++]));
    
    string temp = "";
    while (idx < str.size() && isdigit(str[idx]))
        temp.push_back(str[idx++]);
        
    num = stoi(temp);
}

bool Cmp(const string& a, const string& b)
{
    string headA = "", headB = "";
    int numA = 0, numB = 0;
    
    FindHeadNum(a, headA, numA);
    FindHeadNum(b, headB, numB);
    
    if (headA == headB)
        return numA < numB;        
    
    return headA < headB;
}

vector<string> solution(vector<string> files) 
{
    stable_sort(files.begin(), files.end(), Cmp);
    return files;
}