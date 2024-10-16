#include <iostream>
using namespace std;

bool solution(string s)
{
    int P = 0, Y = 0;
    for (char c : s)
    {
        char Alpha = tolower(c);
        if ('p' == Alpha) ++P;
        if ('y' == Alpha) ++Y;
    }

    return P == Y;
}