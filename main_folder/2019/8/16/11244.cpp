#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<string> vs;
int r, c;
vs G;

int dx[] = {1, 1,  1, 0,  0, -1, -1, -1};
int dy[] = {1, 0, -1, 1, -1,  1,  0, -1};

bool isStar(int y, int x)
{
	bool res = true;
	for (int i = 0; i < 8; ++i)
	{
		int xx = x + dx[i], yy = y + dy[i];
		if (xx >= 0 && yy >= 0 && xx < c && yy < r)
			res &= (G[yy][xx] == '.');
	}
	return res;
}

void dfs(int y, int x)
{
	if (x >= 0 && y >= 0 && x < c && y < r && G[y][x] == '*')
	{
		G[y][x] = '.';
		for (int i = 0; i < 8; ++i)
			dfs(y + dy[i], x + dx[i]);
	}
}

int main()
{
	while (cin >> r >> c, r || c)
	{
		G.resize(r);
		int cnt = 0;
		for (int i = 0; i < r; ++i)
			cin >> G[i];
			
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c ; ++j)
				if (G[i][j] == '*')
				{
					if (isStar(i, j))
						++cnt;
					dfs(i, j);
				}
		cout << cnt << '\n';
	}
}
