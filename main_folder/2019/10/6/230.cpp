#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
using namespace std;

#define MP make_pair
typedef vector<int> vi;

int main()
{
	vector<pair<string,string> > Lib;
	vi Ret;
	string a;
	
	while (getline(cin, a), a != "END")
		for (int i = 1; i < a.size(); ++i)
			if (a[i] == '\"' )
			{
				Lib.push_back(MP(a.substr(i+5, string::npos), a.substr(0, i + 1)));
				break;
			}
	
	sort(Lib.begin(), Lib.end());
	vi BS(Lib.size(),1);
	
	while (getline(cin, a), a != "END")
	{		
		if (a[0] == 'B')
		{
			string book = a.substr(7, a.size());
			for (int j = 0; j < Lib.size(); ++j)
				if (Lib[j].second == book)
				{
					BS[j] = 0;
					break;
				}
			continue;
		}
		else if (a[0] == 'R')
		{
			string book = a.substr(7, a.size());
			for (int j = 0; j < Lib.size(); ++j)
				if (Lib[j].second == book)
				{
					BS[j] = 1;
					Ret.push_back(j);
					break;
				}
			continue;
		}
		
		sort(Ret.begin(), Ret.end());
		for (int i : Ret)
		{
			int prev = i - 1;
			while (prev >= 0 && BS[prev] == 0)
				prev--;
				
			if (prev != -1)
				cout << "Put " << Lib[i].second << " after " << Lib[prev].second << '\n';
			else
				cout << "Put " << Lib[i].second << " first\n";								
		}

		cout << "END\n";
		Ret.clear();
	}		
}
