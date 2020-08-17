#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void dfs(vvi& G, vi& V, int u, int j = -1)
{
	V[u] = 1;
	for (int i = 0; i < G[u].size(); ++i)
		if (G[u][i] && !V[i] && i != j)
			dfs(G, V, i, j);
}

int main()
{
	int T, n;
	cin >> T;
	for (int c = 1; c <= T; ++c)
	{
		cin >> n;
		vvi G(n, vi(n));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> G[i][j];

		vi V(n, 0);
		dfs(G, V, 0);
		
		string s = "+" + string(2 * n - 1, '-') + "+\n";
		cout << "Case " << c << ":\n" << s;
		
		for (int j = 0; j < n; ++j)
			cout << (V[j] ? "|Y" :"|N");
		cout << "|\n" + s;
		
		for (int i = 1; i < n; ++i)
		{
			vi W(n, 0);
			dfs(G, W, 0, i);
			
			for (int j = 0; j < n; ++j)
				cout << ((i == j && V[j]) || (V[j] && !W[j]) ? "|Y" : "|N");
			cout << "|\n" + s;
		}		
	}
}
