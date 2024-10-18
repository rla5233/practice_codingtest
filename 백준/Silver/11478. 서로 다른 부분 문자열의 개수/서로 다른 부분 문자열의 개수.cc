#include <iostream>
#include <unordered_set>

int main()
{
    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(0); std::cout.tie(0);;

    std::string S = "";
    std::cin >> S;

    std::unordered_set<std::string> PartStr;
    for (int Len = 1; Len <= S.size(); ++Len)
    {
        for (int i = 0; i <= S.size() - Len; ++i)
            PartStr.insert(S.substr(i, Len));
    }
    
    std::cout << PartStr.size();

    return 0;
}