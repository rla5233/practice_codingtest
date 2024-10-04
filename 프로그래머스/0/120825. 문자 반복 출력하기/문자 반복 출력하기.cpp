#include <string>
#include <vector>

std::string solution(std::string MyString, int N) 
{
    std::string Result = "";
    for (char C : MyString)
    {
        for (int i = 0; i < N; ++i)
        {
            Result.push_back(C);
        }
    }

    return Result;
}