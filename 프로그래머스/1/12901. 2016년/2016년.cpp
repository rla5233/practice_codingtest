#include <string>
#include <vector>

std::string solution(int A, int B) 
{
    std::vector<std::pair<int, int>> MtoD = 
    { 
        { 1, 31 }, { 2, 29 }, { 3, 31 }, 
        { 4, 30 }, { 5, 31 }, { 6, 30 }, 
        { 7, 31 }, { 8, 31 }, { 9, 30 }, 
        { 10, 31 }, { 11, 30 }, { 12, 31 }, 
    };

    std::vector<std::pair<int, std::string>> DofW =
    {
        { 0, "THU" }, { 1, "FRI" }, { 2, "SAT" },
        { 3, "SUN" }, { 4, "MON" }, { 5, "TUE" }, { 6, "WED" },
    };

    int Day = 0;
    for (int i = 0; i < A - 1; i++)
    {
        Day += MtoD[i].second;
    }

    Day += B;
    return DofW[Day % 7].second;
}