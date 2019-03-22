#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<string> vs;
vs G;
int n;
int dx[] = {1, -1, 0,  0};
int dy[] = {0,  0, 1, -1};

bool dfs(int y, int x)
{
	bool res = false;
	if (x >= 0 && y >= 0 && x < n && y < n && G[y][x] != '.')
	{
		res = G[y][x] == 'x' ? true : false;
		G[y][x] = '.';
		for (int i = 0; i < 4; ++i)
			res |= dfs(y + dy[i], x + dx[i]);
	}
	return res;
}

int main()
{
	int T;
	cin >> T;
	for (int c_nr = 1; c_nr <= T; ++c_nr)
	{
		cin >> n;
		G.resize(n);
		for (int i = 0; i < n; ++i)
			cin >> G[i];
			
		int ships = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (G[i][j] != '.')
					ships += dfs(i, j);
		
		cout << "Case " << c_nr << ": " << ships << '\n';
	}	
}
