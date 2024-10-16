#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int Max_X = -10000, Min_X = 10000;
    int Max_Y = -10000, Min_Y = 10000;

    int N = 0;
    std::cin >> N;
    while (N--)
    {
        int X = 0, Y = 0;
        std::cin >> X >> Y;

        if (X < Min_X) Min_X = X;
        if (X > Max_X) Max_X = X;
        if (Y < Min_Y) Min_Y = Y;
        if (Y > Max_Y) Max_Y = Y;
    }

    std::cout << (Max_X - Min_X) * (Max_Y - Min_Y);

    return 0;
}