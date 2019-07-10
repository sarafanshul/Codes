#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

vector<vi> G;
vi R, S;

void dfs(int x)
{
	S[x] = 1;
	for (int a : G[x])
		if (!S[a])
			dfs(a);

	R.push_back(x);
}

int main()
{
	int n, m, a, b;
	while (cin >> n >> m, n || m)
	{
		G.assign(n, vector<int>());
		S.assign(n, 0);
		R.clear();
		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b;
			G[a - 1].push_back(b - 1);
		}
		
		for (int i = 0; i < n; ++i)
			if (!S[i])
				dfs(i);
		
		for (auto rit = R.rbegin(); rit != R.rend(); ++rit)
			cout << (rit == R.rbegin() ? "" : " ") << *rit + 1;
		cout << '\n';
	}	
}
