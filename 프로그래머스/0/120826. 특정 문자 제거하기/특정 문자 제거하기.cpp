#include <string>

std::string solution(std::string MyString, std::string Letter) 
{
    std::string Result = "";
    
    for(char C : MyString)
    {
        if(Letter.front() != C)
        {
            Result.push_back(C);
        }
    }
    
    return Result;
}