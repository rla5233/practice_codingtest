#include <vector>
#include <numeric>

std::vector<int> solution(int Numer1, int Denom1, int Numer2, int Denom2) 
{
    int Denom = std::lcm(Denom1, Denom2);
    Numer1 *= Denom / Denom1;
    Numer2 *= Denom / Denom2;

    int Numer = Numer1 + Numer2;
    int GCD = std::gcd(Numer, Denom);
    
    return {Numer / GCD, Denom / GCD};
}
