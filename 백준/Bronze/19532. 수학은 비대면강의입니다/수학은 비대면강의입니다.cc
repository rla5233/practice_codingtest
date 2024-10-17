#include <iostream>

int main()
{
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
    std::cin >> a >> b >> c >> d >> e >> f;

    for (int y = -999; y <= 999; ++y)
    {
        for (int x = -999; x <= 999; ++x)
        {
            if (a * x + b * y == c && d * x + e * y == f)
            {
                std::cout << x << " " << y;
            }
        }
    }

    return 0;
}