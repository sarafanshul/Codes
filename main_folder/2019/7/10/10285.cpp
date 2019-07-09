#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <stack>
using namespace std;

typedef pair<int, int>ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
vvi G, V;
stack<ii> S;

int dx[] = {1, -1, 0,  0};
int dy[] = {0,  0, 1, -1};

void dfs(int y, int x, unsigned h)
{
	if (x >= 0 && y >= 0 && y < G.size() && x < G[0].size() && G[y][x] < h && !V[y][x])
	{
		V[y][x] = 1;
		for (int i = 0; i < 4; ++i)
			dfs(y + dy[i], x + dx[i], G[y][x]);
		S.emplace(y, x);
	}
}

int main()
{
	int t, r, c, x, y;
	cin >> t;
	while (t--)
	{
		string name;
		cin >> name >> r >> c;
		
		G.assign(r, vi(c));
		V.assign(r, vi(c));
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				cin >> G[i][j];

		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				if (!V[i][j])
					dfs(i, j, -1);

		vvi D(r, vi(c, 1)); //Distances
		int top = 0;
		while (!S.empty())
		{
			tie(y, x) = S.top(); S.pop();
			for (int i = 0; i < 4; ++i)
			{
				int xx = x + dx[i], yy = y + dy[i];
				if (xx >= 0 && yy >= 0 && yy < G.size() && xx < G[0].size() && G[yy][xx] < G[y][x] && D[y][x] + 1 > D[yy][xx])
				{
					D[yy][xx] = D[y][x] + 1;
					top = ::max(top, D[yy][xx]);
				}				
			}			
		}
		cout << name << ": " << top << '\n';
	}	
}
