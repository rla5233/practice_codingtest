#include <iostream>

int main(void) 
{
    int N = 0, M = 0;
    std::cin >> N >> M;
    for (int y = 0; y < M; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            std::cout << "*";
        }
        
        std::cout << "\n";
    }
}