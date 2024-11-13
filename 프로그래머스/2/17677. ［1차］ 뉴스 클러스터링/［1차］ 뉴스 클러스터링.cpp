#include <string>
#include <unordered_map>

using namespace std;

void MakeMulSet(unordered_map<string, int>& _Map, const string& _Str)
{
    for (int i = 0; i < static_cast<int>(_Str.size()) - 1; ++i)
    {
        char Temp1 = toupper(_Str[i]), Temp2 = toupper(_Str[i + 1]);
        if (isalpha(Temp1) && isalpha(Temp2))
        {
            string Word = "";
            Word.push_back(Temp1);
            Word.push_back(Temp2);
            ++_Map[Word];
        }
    }
}

int solution(string _Str1, string _Str2) 
{
    unordered_map<string, int> A, B;
    MakeMulSet(A, _Str1);
    MakeMulSet(B, _Str2);
    
    int Union = 0, Intersection = 0;
    for (const auto& Pair : A)
    {
        auto FindIter = B.find(Pair.first);
        if (B.end() != FindIter)
        {
            Intersection += min(Pair.second, B[Pair.first]);
            Union += max(Pair.second, B[Pair.first]);
            B.erase(FindIter);
        }
        else
            Union += Pair.second;
    }
        
    for (const auto& Pair : B)
        Union += Pair.second;
    
    return 0 == Union ? 65536 : 65536 * Intersection / Union;
}