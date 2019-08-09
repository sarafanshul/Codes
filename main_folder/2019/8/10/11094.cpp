#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef vector<string> vs;
vs G;
int area = 0;

int dx[] = {1, 0,  0, -1};
int dy[] = {0, 1, -1,  0};

void toLower()
{
	for (int i = 0; i < G.size(); ++i)
		transform(G[i].begin(), G[i].end(), G[i].begin(), ::tolower);
}

void dfs(int x, int y, char w)
{
	if (x >= 0 && y >= 0 && x < G.size() && y < G[0].size() && G[x][y] != w)
	{
		++area;
		G[x][y] = w;
		for (int i = 0; i < 4; ++i)
			dfs(x + dx[i], (y + dy[i] + G[0].size()) % G[0].size(), w);
	}	
}

int main()
{
	int m, n, x, y;
	while (cin >> m >> n)
	{
		G.resize(m);
		for (int i = 0; i < m; ++i)
			cin >> G[i];
			
		toLower();
		
		cin >> x >> y;
		char land = G[x][y];
		int it = 0, found = -1, M = 0;
		while (found == -1 && it < m)
			found = G[it++].find_first_not_of(land);
		char water = it != -1 ? G[it - 1][found] : 0;
		
		if (!water)
		{
			cout << "0\n";
			continue;
		}		
		dfs(x, y, water);
		
		for(int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				if (G[i][j] != water)
				{
					area = 0;
					dfs(i, j, water);
					if (area > M)
						M = area;
				}
		cout << M << '\n';
	}	
}
