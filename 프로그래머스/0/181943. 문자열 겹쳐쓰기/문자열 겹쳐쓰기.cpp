#include <string>
#include <vector>


std::string solution(std::string My_string, std::string Overwrite_string, int S) 
{
    std::string Result = "";
   
    for(int i = 0; i < My_string.size(); ++i)
    {
        if (S == i)
        {
            for(int j = 0; j < Overwrite_string.size(); ++j)
            {
                Result += Overwrite_string[j];
            }
            
            i += Overwrite_string.size() - 1;
        }
        else
        {
            Result += My_string[i];
        }        
    }
    
    return Result;
}