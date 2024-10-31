#include <vector>
#include <unordered_set>
#include <numeric>

using namespace std;

int solution(vector<int> Elements) 
{
    vector<int> Circle = Elements;
    for (int Num : Elements)
        Circle.push_back(Num);
    
    unordered_set<int> PartSum;
    for (int i = 0; i < Elements.size(); i++)
    {
        int Left = 0, Right = i + 1;
        int Sum = accumulate(Circle.begin(), Circle.begin() + Right, 0);
        PartSum.insert(Sum);
        
        while(Left < Elements.size())
        {
            Sum += Circle[Right++];
            Sum -= Circle[Left++];
            PartSum.insert(Sum);
        }
    }
    
    return PartSum.size();
}