#include <iostream>

int main(void) 
{
    int N = 0;
    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < i + 1; ++j)
        {
            std::cout << "*";
        }

        std::cout << "\n";
    }
}