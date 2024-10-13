#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    size_t Temp = num;
    int answer = 0;
    while (1 != Temp)
    {
        (Temp & 1) ? Temp = (3 * Temp) + 1 : Temp >>= 1;
        ++answer;

        if (500 < answer) {
            answer = -1;
            break;
        }
    }

    return answer;
}
