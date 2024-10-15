#include <string>

using namespace std;

string solution(string s) 
{
    string answer = "";

    int Idx = 0;
    for (char C : s)
    {
        (Idx++ & 1) ? answer.push_back(tolower(C)) : answer.push_back(toupper(C));

        if (' ' == C)
            Idx = 0;
    }

    return answer;
}