#include <string>
#include <vector>

std::vector<int> solution(std::string S) 
{
    std::vector<int> Result(2, 0);
    while ("1" != S)
    {
        int Size = 0;
        for(int C : S)
        {
            if ('1' == C)
                ++Size;
            else
                ++Result[1];
        }
        
        std::string Temp = "";
        while (0 != Size)
        {
            if (Size & 1)
                Temp = '1' + Temp;
            else
                Temp = '0' + Temp;
            
            Size >>= 1;
        }
        
        S.swap(Temp);
        ++Result[0];
    }
    
    return Result;
}