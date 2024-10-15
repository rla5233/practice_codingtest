#include <iostream>
#include <vector>

int K = 0;
std::vector<int> V, Temp;

void Merge(int Left, int Mid, int Right)
{
    int T = Left;
    int L = Left, R = Mid + 1;
    while (L <= Mid && R <= Right)
    {
        if (V[L] <= V[R])
            Temp[T++] = V[L++];
        else
            Temp[T++] = V[R++];
    }

    while (L <= Mid)
        Temp[T++] = V[L++];
    while (R <= Right)
        Temp[T++] = V[R++];

    for (int i = Left; i <= Right; ++i)
    {
        V[i] = Temp[i];
        if (--K == 0)
            std::cout << V[i];
    }
}

void MergeSort(int Left, int Right)
{
    if (Left < Right)
    {
        int Mid = (Left + Right) / 2;
        MergeSort(Left, Mid);
        MergeSort(Mid + 1, Right);
        Merge(Left, Mid, Right);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(0); std::cout.tie(0);

    int A = 0;
    std::cin >> A >> K;

    while (A--)
    {
        int Num = 0;
        std::cin >> Num;
        V.push_back(Num);
    }

    Temp.resize(V.size());
    MergeSort(0, V.size() - 1);

    if (K > 0)
        std::cout << -1;

    return 0;
}