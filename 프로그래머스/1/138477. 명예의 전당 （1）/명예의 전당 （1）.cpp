#include <string>
#include <vector>
#include <set>

std::vector<int> solution(int K, std::vector<int> Scores) 
{
    std::vector<int> Result(Scores.size(), 0);
    
    std::multiset<int> Board;
    for (size_t i = 0; i < Scores.size(); ++i)
    {
        Board.insert(Scores[i]);
        if (K < Board.size())
        {
            Board.erase(Board.begin());
        }

        Result[i] = (*(Board.begin()));
    }

    return Result;
}