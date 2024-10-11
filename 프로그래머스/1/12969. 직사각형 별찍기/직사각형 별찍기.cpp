#include <iostream>

int main(void) 
{
    int N = 0, M = 0;
    std::cin >> N >> M;

    std::string Star(N, '*');
    for (int x = 0; x < M; ++x)
        std::cout << Star << "\n";
}