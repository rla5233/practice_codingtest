#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for (long long x : numbers) 
    {
        if (x % 2 == 0) 
        {
            answer.push_back(x + 1);
        } 
        else 
        {
            long long next = x + (x & -x);
            long long adjust = ((x ^ next) / (x & -x)) >> 2;
            answer.push_back(next | adjust);
        }
    }

    return answer;
}