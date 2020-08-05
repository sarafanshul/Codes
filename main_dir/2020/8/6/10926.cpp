#include <iostream>
#include <vector>
using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;

int dfs(vvi& G, vb& V, int u)
{
	int ret = 1;
	V[u] = true;
	for (int i = 0; i < G[u].size(); ++i)
		if (!V[G[u][i]])
			ret += dfs(G, V, G[u][i]);
	
	return ret;
}


int main()
{
	int n, t, u;
	while(cin >> n, n)
	{
		vb zeroIn(n, true);
		vvi G(n, vi());
		for (int i = 0; i < n; ++i)
		{
			cin >> t;
			while (t--)
			{
				cin >> u;
				G[i].push_back(u - 1);
				zeroIn[u - 1] = false;
			}
		}
		
		int ind = -1, res = -1;
		for (int i = 0; i < n; ++i)
			if (zeroIn[i])
			{
				vb V(n, false);
				int dep = dfs(G, V, i);
				if (dep > res)
					ind = i, res = dep;
			}
				
		cout << ind + 1 << '\n';
	}
}
