#include <vector>

int solution(int N, std::vector<int> Lost, std::vector<int> Reserve)
{
    std::vector<int> Student(32, 0);
    for (int Num : Lost) --Student[Num];
    for (int Num : Reserve) ++Student[Num];

    int Result = 0;
    for (int i = 1; i <= N; i++)
    {
        if (-1 == Student[i])
        {
            if (1 == Student[i - 1]) 
                Student[i] = (Student[i - 1] = 0);
            else if (1 == Student[i + 1]) 
                Student[i] = (Student[i + 1] = 0);
        }

        if (0 <= Student[i]) ++Result;
    }

    return Result;
}