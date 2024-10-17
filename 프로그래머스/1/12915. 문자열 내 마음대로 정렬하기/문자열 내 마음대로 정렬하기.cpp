#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> solution(std::vector<std::string> Strings, int N) 
{
    std::sort(Strings.begin(), Strings.end(), [&](const std::string& A, const std::string& B)
        {
            return (A[N] == B[N]) ? A < B : A[N] < B[N];
        }
    );

    return Strings;
}