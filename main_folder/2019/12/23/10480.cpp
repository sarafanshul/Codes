#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

bool ap(vvi& G, int R[][50], vi& P)
{
	queue<int> Q;
	Q.push(0);
	
	while (!Q.empty())
	{
		int u = Q.front(); Q.pop();
		if (u == 1)
			return true;
		
		for (int v : G[u])
			if (P[v] == -1 && R[u][v] > 0)
				P[v] = u, Q.push(v);			
	}
	
	return false;
}

void dfs(int u, vi& P, vvi& G, int R[][50])
{
	P[u] = 1;
	for (int v : G[u])
		if (!P[v] && R[u][v] > 0)
			dfs(v, P , G, R);	
}

int main()
{
	int m, n, x, y, w;
	while (cin >> n >> m, m || n)
	{
		vvi G(n, vi());
		int R[50][50] = {};
		
		for (int i = 0; i < m; ++i)
		{
			cin >> x >> y >> w;
			G[x - 1].push_back(y - 1);
			G[y - 1].push_back(x - 1);
			R[x - 1][y - 1] += w;
			R[y - 1][x - 1] += w;
		}
		
		vi P(n, -1);		
		while (ap(G, R, P))
		{
			int aug = 40000001;
			for (int i = 1; i != 0; i = P[i])
				aug = ::min(aug, R[P[i]][i]);
				
			for (int i = 1; i != 0; i = P[i])
				R[P[i]][i] -= aug, R[i][P[i]] += aug;
			
			P.assign(n, -1);
		}
		
		//dfs
		P.assign(n, 0);
		dfs(0, P, G, R);		

		for (int i = 0; i < n; ++i)
			if (P[i])
				for (int j : G[i])
					if (!P[j] && R[i][j] == 0)
						cout << i + 1 << " " << j + 1 << "\n";		
		cout << "\n";
	}
	
}
