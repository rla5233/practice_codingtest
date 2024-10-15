#include <iostream>
#include <cmath>

void Cantor(std::string& Str, int Left, int Size)
{
    if (1 <= Size)
    {
        int NextSize = Size / 3;
        Cantor(Str, Left, NextSize);

        int Mid = Left + Size;
        for (int i = Mid; i < Mid + Size; ++i)
            Str[i] = ' ';

        int Right = Mid + Size;
        Cantor(Str, Right, NextSize);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(0); std::cout.tie(0);

    while (true)
    {
        int N = 0;
        std::cin >> N;
        if (std::cin.eof()) break;
            
        int Size = pow(3, N);
        std::string Str(Size, '-');
        Cantor(Str, 0, Size / 3);
        std::cout << Str << '\n';
    }

    return 0;
}