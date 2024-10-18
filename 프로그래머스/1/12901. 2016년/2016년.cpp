#include <string>
#include <vector>

std::string solution(int A, int B) 
{
    std::vector<int> MtoD = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    std::vector<std::string> DofW = { "THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED" };
    
    int Day = 0;
    for (int i = 0; i < A - 1; i++)
        Day += MtoD[i];

    Day += B;
    return DofW[Day % 7];
}