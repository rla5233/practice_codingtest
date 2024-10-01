#include <string>
#include <vector>
#include <unordered_map>

std::vector<int> solution(std::vector<std::string> KeyInput, std::vector<int> Board) 
{
    struct Point
    {
        Point operator+(const Point& Value)
        {
            int RetX = X + Value.X;
            int RetY = Y + Value.Y;
            return { RetX, RetY };
        }

        int X = 0;
        int Y = 0;
    };

    std::unordered_map<std::string, Point> KeyDir;
    KeyDir["up"] = { 0, 1 }; KeyDir["down"] = { 0, -1 };
    KeyDir["left"] = { -1, 0 }; KeyDir["right"] = { 1, 0 };

    Point Cur = { 0, 0 };
    Point Min = { (1 - Board[0]) / 2, (1 - Board[1]) / 2 }, Max = { -Min.X, -Min.Y };
    for (const std::string& Input : KeyInput)
    {
        Point Next = Cur + KeyDir[Input];
        if (Min.X <= Next.X && Max.X >= Next.X && Min.Y <= Next.Y && Max.Y >= Next.Y)
        {
            Cur = Next;
        }
    }

    return { Cur.X, Cur.Y };
}