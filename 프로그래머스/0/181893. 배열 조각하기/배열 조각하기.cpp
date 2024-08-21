#include <string>
#include <vector>

std::vector<int> solution(std::vector<int> Arr, std::vector<int> Query)
{
    std::vector<int> Result = Arr;

    for (int i = 0; i < Query.size(); ++i)
    {
        std::vector<int> Temp;
        if (0 == i % 2)
        {
            for (int j = 0; j <= Query[i]; ++j)
            {
                Temp.push_back(Result[j]);
            }

            Result.swap(Temp);
        }
        else
        {
            for (int j = Query[i]; j < Result.size(); ++j)
            {
                Temp.push_back(Result[j]);
            }

            Result.swap(Temp);
        }
    }

    return Result;
}