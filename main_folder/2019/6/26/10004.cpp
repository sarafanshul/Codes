#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
vvi G;
vi Col;

bool dfs(int v, int color)
{	
	bool res = true;
	Col[v] = color;
	for (int i = 0; i < G[v].size(); ++i)
	{
		if (Col[G[v][i]] == color)
			return false;
					
		if (Col[G[v][i]] == -1)
			res &= dfs(G[v][i], !color);
	}
	return res;
}

int main()
{
	int v, e;
	while (cin >> v >> e, v)
	{
		G.assign(v, vi());
		Col.assign(v, -1);
		for (int i = 0; i < e; ++i)
		{
			int l, r;
			cin >> l >> r;
			G[l].push_back(r);
			G[r].push_back(l);
		}

		bool res = dfs(0, 0);
		cout << (res ? "" : "NOT ") << "BICOLORABLE.\n";
	}	
}

