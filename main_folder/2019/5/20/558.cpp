#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> iii;

int main()
{
	int c, n, m, x, y, t;
	cin >> c;
	while (c--)
	{
		cin >> n >> m;
		vector<iii> E;
		for (int j = 0; j < m; ++j)
		{
			cin >> x >> y >> t;
			E.emplace_back(x, y, t);
		}
		
		vector<int> d(n, 100000);
		d[0] = 0;
		
		for (int k = 0; k < n; ++k)
			for (int i = 0; i < m; ++i)
			{
				tie(x, y, t) = E[i];
				if (d[x] + t < d[y])
					d[y] = d[x] + t;
			}
			
		bool cycle = false;	
		for (int i = 0; i < m; ++i)
		{
			tie(x, y, t) = E[i];
			if (d[x] + t < d[y])
				cycle = true;
		}
			
		cout << (cycle ? "possible\n" : "not possible\n");
	}	
}
