#include <vector>
#include <algorithm>

std::vector<int> solution(std::vector<int> NumList, int N) 
{
    std::sort(NumList.begin(), NumList.end(), [=](int A, int B)
        {
            if (abs(N - A) == abs(N - B))
            {
                return A > B;
            }

            return abs(N - A) < abs(N - B);
        }
    );

    return NumList;
}