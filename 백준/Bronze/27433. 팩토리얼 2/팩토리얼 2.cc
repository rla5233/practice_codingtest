#include <iostream>

size_t Factorial(int N)
{
    if (0 == N) return 1;
    return N * Factorial(N - 1);
}

int main()
{
    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(0); std::cout.tie(0);
    
    int N = 0;
    std::cin >> N;
    std::cout << Factorial(N);

    return 0;
}