#include <iostream>
#include <numeric>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    long long A = 0, B = 0;
    cin >> A >> B;
    cout << lcm(A, B);

    return 0;
}