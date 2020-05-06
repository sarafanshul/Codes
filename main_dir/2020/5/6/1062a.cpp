#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

string str, heads;

int f(int cnt)
{
	for (int k = 0; k < heads.size(); ++k)
		if (str[cnt] <= heads[k])
		{	
			heads[k] = str[cnt];
			return 0;
		}
		
	heads.append(1, str[cnt]);
	return 1;
}


int main()
{
	int case_nr = 0;
	while (cin >> str, str != "end")
	{
		int res = 0;
		heads = "";
		for (int i = 0; i < str.size(); ++i)
			res += f(i);
		cout << "Case " << ++case_nr << ": " << res << '\n';
	}
}
