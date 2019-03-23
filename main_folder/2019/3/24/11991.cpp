#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
	int n, m, t, s;
	while (cin >> n >> m)
	{
		map<int, vector<int> > M;		
		for (int i = 1; i <= n; ++i)
		{
			cin >> t;
			M[t].push_back(i);
		}
		
		for (int i = 1; i <= m; ++i)
		{
			cin >> t >> s;
			if (M[s].size() >= t)
				cout << M[s][t - 1] << '\n';
			else
				cout << 0 << '\n';
		}
	}
}
