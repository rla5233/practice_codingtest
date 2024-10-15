#include <string>

using namespace std;

string solution(string s, int n) 
{
    string answer = "";
    for (char C : s)
    {
        if (' ' == C)
            answer += ' ';
        else if (isupper(C))
            answer += 'A' + (C - 'A' + n) % 26;
        else if (islower(C))
            answer += 'a' + (C - 'a' + n) % 26;
    }

    return answer;
}