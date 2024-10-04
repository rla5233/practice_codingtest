#include <string>
#include <vector>

int solution(int Angle) 
{
    if (0 < Angle && 90 > Angle)
    {
        return 1;
    }
    else if (90 == Angle)
    {
        return 2;
    }
    else if (90 < Angle && 180 > Angle)
    {
        return 3;
    }
    else
    {
        return 4;
    }
}