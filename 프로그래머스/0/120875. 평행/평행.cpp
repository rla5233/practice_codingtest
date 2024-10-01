#include <vector>

int solution(std::vector<std::vector<int>> Dots) 
{
    std::vector<std::vector<int>> Indexs = { {0, 1, 2, 3}, { 0, 2, 1, 3 }, { 0, 3, 1, 2 } };
    for (const std::vector<int>& Index : Indexs)
    {
        int X1 = Dots[Index[0]][0], Y1 = Dots[Index[0]][1];
        int X2 = Dots[Index[1]][0], Y2 = Dots[Index[1]][1];
                           
        int X3 = Dots[Index[2]][0], Y3 = Dots[Index[2]][1];
        int X4 = Dots[Index[3]][0], Y4 = Dots[Index[3]][1];

        int Mul1 = (Y2 - Y1) * (X4 - X3);
        int Mul2 = (Y4 - Y3) * (X2 - X1);

        if (Mul1 == Mul2)
        {
            return 1;
        }
    }

    return 0;
}