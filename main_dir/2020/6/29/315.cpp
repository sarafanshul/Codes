#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <string>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
vvi G;
vi parent, dfs_low, dfs_num, ArtPt;
int dfsCnt, dfsRoot, rootChild;

void artPts(int u)
{
	dfs_low[u] = dfs_num[u] = dfsCnt++;
	for (int i = 0; i < G[u].size(); ++i)
	{		
		int v = G[u][i];		
		parent[v] = u;
		
		if (dfs_num[v] == -1)
		{
			if (u == dfsRoot)
				++rootChild;
			
			artPts(v);
			if (dfs_low[v] >= dfs_num[u])
				ArtPt[u] = 1;
			
			dfs_low[u] = ::min(dfs_low[u], dfs_low[v]);
		}
		else if (v != parent[u])
			dfs_low[u] = ::min(dfs_low[u], dfs_num[v]);
	}
}

int main()
{
	int n, u, v;
	string s;
	while (cin >> n, n)
	{
		cin.ignore();
		G.assign(n, vi()); parent.assign(n, 0), ArtPt.assign(n, 0);
		dfs_low.assign(n, 0); dfs_num.assign(n, -1);
		
		while (getline(cin, s), s != "0")
		{
			istringstream iss(s);
			iss >> u;
			while (iss >> v)
				G[u - 1].push_back(v - 1), G[v - 1].push_back(u - 1);
		}
		
		dfsCnt = 0;
		for (int i = 0; i < n; ++i)
			if (dfs_num[i] == -1)
			{
				dfsRoot = i; rootChild = 0;
				artPts(i);
				ArtPt[i] = rootChild > 1;
			}

		cout << count(ArtPt.begin(), ArtPt.end(), 1) << '\n';
	}
}
