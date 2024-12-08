#include <string>
#include <vector>

using namespace std;

string solution(string number, int k)
{
    string answer = "";
    for (char e : number)
    {
        while (!answer.empty() && 0 < k && answer.back() < e)
        {
            answer.pop_back();
            --k;
        }

        answer.push_back(e);
    }

    while (k--)
        answer.pop_back();

    return answer;
}