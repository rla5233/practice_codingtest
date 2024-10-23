#include <string>

std::string solution(std::string S) 
{
    S.front() = std::toupper(S.front());
    for (int i = 1; i < S.size(); ++i)
    {
        if (' ' == S[i - 1])
            S[i] = std::toupper(S[i]);
        else
            S[i] = std::tolower(S[i]);
    }
    
    return S;
}