#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) 
{
    int Index = distance(seoul.begin(), find(seoul.begin(), seoul.end(), "Kim"));
    return "김서방은 " + to_string(Index) + "에 있다";
}