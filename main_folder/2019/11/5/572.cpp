#include <iostream>
#include <vector>
using namespace std;

typedef vector<string> vs;

int dx[] = {1, 1,  1, 0,  0, -1, -1, -1};
int dy[] = {1, 0, -1, 1, -1,  1,  0, -1};

void dfs(const vs &G, vs &V, int x, int y)
{
	V[x][y] = '1';
	for (int i = 0; i < 8; ++i)
	{
		int xx = x + dx[i], yy = y + dy[i];
		if (xx >= 0 && yy >= 0 && xx < G.size() && yy < G[0].size() && V[xx][yy] == '0')
			if (G[xx][yy] == '@')
				dfs(G, V, xx, yy);
			else
				V[xx][yy] = '1';		
	}
}

int main()
{
	int m, n;
	while (cin >> m >> n, m)
	{
		int res = 0;
		vs G(m), V(m, string(n, '0'));
		for (int i = 0; i < m; ++i)
			cin >> G[i];
			
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				if (V[i][j] == '0' && G[i][j] == '@')
					++res, dfs(G, V, i, j);
		cout << res << '\n';
	}
}
