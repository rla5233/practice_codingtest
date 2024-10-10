#include <vector>
#include <stack>

int solution(std::vector<std::vector<int>> Board, std::vector<int> Moves) 
{
    std::vector<std::stack<int>> Doll;
    Doll.resize(Board.size());
    for (int y = Board.size() - 1; y >= 0; --y)
    {
        for (int x = Board[y].size() - 1; x >= 0; --x)
        {
            if (0 != Board[y][x])
            {
                Doll[x].push(Board[y][x]);
            }
        }
    }

    int Result = 0;
    std::stack<int> Basket;
    for (int Move : Moves)
    {
        int Idx = Move - 1;
        if (!Doll[Idx].empty())
        {
            if (Basket.empty() || Basket.top() != Doll[Idx].top())
            {
                Basket.push(Doll[Idx].top());
                Doll[Idx].pop();
            }
            else
            {
                Basket.pop();
                Doll[Idx].pop();
                Result += 2;
            }
        }
    }

    return Result;
}