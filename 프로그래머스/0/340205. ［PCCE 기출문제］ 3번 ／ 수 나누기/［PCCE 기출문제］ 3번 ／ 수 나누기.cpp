#include <iostream>

using namespace std;

int main(void) {
    int number;
    cin >> number;
    
    int answer = 0;
    
    while(0 != number){
        answer += number % 100;
        number /= 100;
    }
    cout << answer << endl;
    return 0;
}