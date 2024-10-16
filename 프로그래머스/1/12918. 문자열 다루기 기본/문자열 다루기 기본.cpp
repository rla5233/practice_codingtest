#include <string>

using namespace std;

bool solution(string s) 
{
    int Size = s.size();
    for (char c : s)
    {
        if (!isdigit(c)) 
            return false;
    }

    return (4 == Size) || (6 == Size) ? true : false;
}