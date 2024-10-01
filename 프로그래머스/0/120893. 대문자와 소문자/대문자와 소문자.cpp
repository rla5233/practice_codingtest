#include <string>
#include <algorithm>

std::string solution(std::string S) 
{
    std::transform(S.begin(), S.end(), S.begin(), [&](char C)->char
        {
            return islower(C) ? C = toupper(C) : C = tolower(C);
        }
    );
    
    return S;
}