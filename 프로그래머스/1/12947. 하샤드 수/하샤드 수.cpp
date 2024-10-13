#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int Num = x, Sum = 0;
    while (0 != Num)
    {
        Sum += Num % 10;
        Num /= 10;
    }

    return (x % Sum) ? false : true;
}