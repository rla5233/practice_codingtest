#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int Min = *min_element(arr.begin(), arr.end());
    for (int Num : arr)
        if (Min != Num) 
            answer.push_back(Num);
    
    return answer.empty() ?  std::vector<int>(1, -1) : answer;
}