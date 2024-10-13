#include <vector>

using namespace std;

double solution(vector<int> arr) {
    int Sum = 0;
    for (auto& Num : arr)
        Sum += Num;

    return Sum / static_cast<double>(arr.size());
}