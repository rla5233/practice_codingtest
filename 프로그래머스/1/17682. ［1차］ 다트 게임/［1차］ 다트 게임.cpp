#include <sstream>
#include <string>
#include <cmath>

int solution(std::string DartResult) 
{
    int Result = 0;
    int Prev = 0, Cur = 0;
    std::stringstream SS(DartResult);
    for (int i = 0; i < 3; ++i)
    {
        char Pow, Opt;

        SS >> Cur;
        Pow = SS.get(); 
        Opt = SS.get();
        
        if ('D' == Pow) 
            Cur = pow(Cur, 2);
        else if ('T' == Pow) 
            Cur = pow(Cur, 3);

        if ('*' != Opt && '#' != Opt)
            SS.unget();
        else if ('*' == Opt)
            Prev <<= 1, Cur <<= 1;
        else if ('#' == Opt)
            Cur *= -1;

        Result += Prev;
        Prev = Cur;
        Cur = 0;
    }

    Result += Prev;
    return Result;
}