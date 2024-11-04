#include <string>
#include <vector>

using namespace std;

vector<int> solution(int N, long long Left, long long Right) 
{
    vector<int> Answer(Right - Left + 1, 0);
    for (int i = 0; i <= Right - Left; ++i)
    {
        int Row = (Left + i) / N, Col = (Left + i) % N;
        Row >= Col ? Answer[i] = Row + 1 : Answer[i] = Col + 1;
    }
    
    return Answer;
}