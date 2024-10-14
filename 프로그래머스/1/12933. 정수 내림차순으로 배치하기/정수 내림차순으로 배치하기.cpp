#include <string>
#include <algorithm>

using namespace std;

long long solution(long long n) 
{
    string Num = to_string(n);
    sort(Num.rbegin(), Num.rend());
    return stoll(Num);
}