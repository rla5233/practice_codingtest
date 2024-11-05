#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int left = 0, right = 0;
    int currentSum = 0, count = 0;

    while (right < N) {
        currentSum += nums[right];
        
        while (currentSum > M && left <= right) {
            currentSum -= nums[left++];
        }

        if (currentSum == M) {
            count++;
        }

        right++;
    }

    cout << count << "\n";
    return 0;
}