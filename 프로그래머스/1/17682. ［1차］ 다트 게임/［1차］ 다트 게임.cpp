#include <string>
#include <cmath>

int solution(std::string DartResult) 
{
    int Result = 0, Prev = 0, Cur = 0;
    for (int i = 0; i < DartResult.size(); ++i)
    {
        if (isdigit(DartResult[i]))
        {
            if (isdigit(DartResult[i + 1])) 
                Cur = std::stoi(DartResult.substr(i++, 2));
            else 
                Cur = DartResult[i] - '0';
            continue;
        }

        if (isalpha(DartResult[i]))
        {
            if ('D' == DartResult[i])
                Cur = pow(Cur, 2);
            else if ('T' == DartResult[i])
                Cur = pow(Cur, 3);

            if (i + 1 < DartResult.size() && '#' == DartResult[i + 1])
            {
                Cur *= -1;
                ++i;
            }
            else if (i + 1 < DartResult.size() && '*' == DartResult[i + 1])
            {
                Prev <<= 1, Cur <<= 1;
                ++i;
            }

            Result += Prev;
            Prev = Cur;
            Cur = 0;
        }
    }

    Result += Prev;
    return Result;
}