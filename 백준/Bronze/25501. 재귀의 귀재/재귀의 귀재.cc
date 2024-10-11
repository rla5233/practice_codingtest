#include <iostream>

std::pair<bool, int> Recursion(const std::string& S, int L, int R, int CallCount) 
{
    if (L >= R)
        return { true, CallCount };
    else if (S[L] != S[R])
        return { false, CallCount };
    else
        return Recursion(S, L + 1, R - 1, ++CallCount);
}

std::pair<bool, int> isPalindrome(const std::string& S)
{
    int CallCount = 1;
    return Recursion(S, 0, S.size() - 1, CallCount);
}

int main()
{
    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(0); std::cout.tie(0);
    
    int T = 0;
    std::cin >> T;
    while (T--)
    {
        std::string S = "";
        std::cin >> S;
        
        std::pair<bool, int> Result = isPalindrome(S);
        std::cout << Result.first << " " << Result.second << "\n";
    }
    
    return 0;
}