#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> _Phone_book) 
{
    sort(_Phone_book.begin(), _Phone_book.end());
    
    bool Answer = true;
    for (int i = 0; i < static_cast<int>(_Phone_book.size()) - 1; ++i)
    {
        if (_Phone_book[i] == _Phone_book[i + 1].substr(0, _Phone_book[i].size()))
        {
            Answer = false;            
            break;
        }
    }
    
    return Answer;
}