#include <string>

std::string solution(int N) {
    
    std::string Answer = "";

    while (N != 0)
    {
        int Mod = N % 3;

        N /= 3;
        if (0 == Mod)
        {
            --N;
        }

        Answer = "412"[Mod] + Answer;
    }

    return Answer;
}