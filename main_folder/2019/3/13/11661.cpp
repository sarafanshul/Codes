#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

int main()
{
	int l;
	while (cin >> l, l != 0)
	{
		bool ZCheck = false;
		unsigned int mini = -1;
		string s;
		set <int> D, R;
		
		cin >> s;
		for (int i = 0; i < l; ++i)
		{
			if (s[i] == 'Z')
				ZCheck = true;
			else if (s[i] == 'D')
				D.insert(i);
			else if (s[i] == 'R')
				R.insert(i);
		}
		
		if (!ZCheck)
		{
			for (int d : D)
			{	
				unsigned int dist = -1;
				auto it1 = R.upper_bound(d);
				if (it1 != R.end())
					dist = *it1 - d;
									
				if (it1 != R.begin())
					it1--;
					
				dist = min(dist, (unsigned int)(d - *it1));
				
				if (dist < mini)
					mini = dist;				
			}
			cout << mini << '\n';
		}
		else
			cout << 0 << '\n';
	}
	
	return 0;
}
