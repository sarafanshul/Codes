#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
using namespace std;

typedef vector<string> vs;
typedef vector<vs> vvs;

int dx[] = {1, -1, 0,  0, 0,  0};
int dy[] = {0,  0, 1, -1, 0,  0};
int dz[] = {0,  0, 0,  0, 1, -1};
char Dir[] = {'X', 'Y', 'I', 'J', 'W', 'Z'};

int main()
{
	int l, r, c, xx, yy, zz;
	while (cin >> l >> r >> c, l || r || c)
	{
		int S[3], E[3];
		bool out = false;
		vvs D(l, vs(r));
		for (int i = 0; i < l; ++i)
			for (int j = 0; j < r; ++j)
			{
				cin >> D[i][j];
				int s = D[i][j].find('S'), e = D[i][j].find('E');
				if (s != -1)
					tie(S[0], S[1], S[2]) = tie(i, j, s);
				if (e != -1)
					tie(E[0], E[1], E[2]) = tie(i, j, e);
			}
		queue<tuple<int, int, int> > Q;
		Q.emplace(S[0], S[1], S[2]);
		
		while (!Q.empty() && !out)
		{
			int x, y, z;
			tie(z, x, y) = Q.front();
			Q.pop();
			
			for (int i = 0; i < 6; ++i)
			{
				xx = x + dx[i], yy = y + dy[i], zz = z + dz[i];
				if (zz >= 0 && xx >= 0 && yy >= 0 && zz < l && xx < r && yy < c)
					if (D[zz][xx][yy] == '.')
					{
						D[zz][xx][yy] = Dir[i];
						Q.emplace(zz, xx, yy);	
					}
					else if (D[zz][xx][yy] == 'E')
					{
						D[zz][xx][yy] = Dir[i];
						out = true;
					}
			}
		}
		if (out)
		{
			tie(zz, xx, yy) = tie(E[0], E[1], E[2]);
			int steps = -1;
			while (++steps, D[zz][xx][yy] != 'S')
				for (int i = 0; i < 6; ++i)
					if (D[zz][xx][yy] == Dir[i])
					{
						xx -= dx[i], yy -= dy[i], zz -= dz[i];
						break;
					}
			cout << "Escaped in "  << steps << " minute(s).\n";
		}
		else
			cout << "Trapped!\n";	
	}
}
