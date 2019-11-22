#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <functional>
#include <climits>
using namespace std;

typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int dx[] = {1, -1, 0,  0};
int dy[] = {0,  0, 1, -1};

int main()
{
	int T, r, c, w, y, x;
	cin >> T;
	while (T--)
	{
		cin >> r >> c;
		vvi G(r, vi(c)), D(r, vi(c, INT_MAX));
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				cin >> G[i][j];
				
		priority_queue<iii, vector<iii>, greater<iii> > PQ;
		PQ.emplace(G[0][0], 0, 0);
		D[0][0] = G[0][0];
		
		while (!PQ.empty())
		{
			tie(w, y, x) = PQ.top(); PQ.pop();
			if (y == r - 1 && x == c - 1)
				break;
							
			if (w > D[y][x])
				continue;
			
			for (int i = 0; i < 4; ++i)
			{
				int yy = y + dy[i], xx = x + dx[i];
				if (yy >= 0 && xx >= 0 && yy < r && xx < c && w + G[yy][xx] < D[yy][xx])
				{
					D[yy][xx] = w + G[yy][xx];
					PQ.emplace(D[yy][xx], yy, xx);
				}
			}
		}
		cout << D[r - 1][c - 1] << '\n';
	}
}
