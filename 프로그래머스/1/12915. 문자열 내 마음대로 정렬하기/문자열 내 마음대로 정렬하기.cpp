#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> solution(std::vector<std::string> Strings, int N) 
{
    std::sort(Strings.begin(), Strings.end(), [&](const std::string& A, const std::string& B)
        {
            if (A[N] < B[N])
                return true;
            else if (A[N] == B[N])
                return A < B;
            else
                return false;
        }
    );

    return Strings;
}