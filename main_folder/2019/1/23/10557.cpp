#include <iostream>
#include <vector>
#include <climits>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

vvi G;
vb visited;

void dfs(int u)
{
	visited[u] = 1;
	for (auto v : G[u])
		if (!visited[v])
			dfs(v);
}

bool can(int u, int n)
{
	visited.clear();
	visited.resize(n, 0);
	dfs(u);
	return visited[n - 1];
}

int main()
{
	int n;
	while (cin >> n, n != -1)
	{
		int w, v, k;
		G.clear();
		G.resize(n);
		vi W(n), D(n, INT_MAX);
		for (int u = 0; u < n; ++u)
		{
			cin >> w >> k;
			W[u] = -w;
			for (int i = 0; i < k; ++i)
			{
				cin >> v;
				G[u].push_back(v - 1);
			}
		}
		D[0] = -100;
		for (int i = 0; i < n - 1; ++i)
			for (int u = 0; u < n; ++u)
				for (int v : G[u])
					if (D[u] != INT_MAX && D[u] + W[v] < D[v] && D[u] + W[v] < 0)
						D[v] = D[u] + W[v];

		
		bool cycle = (D[n - 1] != INT_MAX);
		for (int u = 0; u < n; ++u)
			for (int v : G[u])
				if (D[u] != INT_MAX && D[u] + W[v] < D[v] && D[u] + W[v] < 0)
					cycle |= can(v, n);					
	
		if (cycle)
			cout << "winnable\n";
		else
			cout << "hopeless\n";
	}
}
