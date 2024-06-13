#include <iostream>
#include <list>
using namespace std;

string s;
int ContextNum;
char Command;
char Addchar;
std::list<char> l;

int main()
{
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		l.push_back(s[i]);
	}

	list<char>::iterator iter = l.end();

	cin >> ContextNum;

	for (int i = 0; i < ContextNum; i++)
	{
		cin >> Command;
		switch (Command)
		{
		case 'P':
			cin >> Addchar;
			l.insert(iter, Addchar);
			break;
		case 'L':
			if (iter != l.begin())
			{
				iter--;
			}
			break;
		case 'D':
			if (iter != l.end())
			{
				iter++;
			}
			break;
		case 'B':
			if (iter != l.begin())
			{
				iter--;
				iter = l.erase(iter);
			}
			break;
		}
	}

	for (char c : l)
	{
		cout << c;
	}
}