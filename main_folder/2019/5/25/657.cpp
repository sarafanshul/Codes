// Rješenje nije baš elegantno, bilo je previše ispravljanja.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<string> vs;
vs G;
vector <int> Dots;

int dx[] = {1,  0, 0, -1};
int dy[] = {0, -1, 1,  0};
int cnt;

void XColor(int x, int y)
{
	G[x][y] = '*';
	for (int i = 0; i < 4; ++i)
	{
		int xx = x + dx[i], yy = y + dy[i];
		if (xx >= 0 && yy >= 0 && xx < G.size() && yy < G[0].size() && G[xx][yy] == 'X')
				XColor(xx, yy);		
	}	
}

void dfs(int x, int y)
{	
	G[x][y] = '.';
	for (int i = 0; i < 4; ++i)
	{
		int xx = x + dx[i], yy = y + dy[i];
		if (xx >= 0 && yy >= 0 && xx < G.size() && yy < G[0].size())
			if (G[xx][yy] == '*')
				dfs(xx, yy);
			else if (G[xx][yy] == 'X')
				++cnt, XColor(xx, yy), dfs(xx, yy);
	}
}

int main()
{
	int w, h, nr = 0;
	while (cin >> w >> h, w || h)
	{
		G.resize(h);
		Dots.clear();
		for (int i = 0; i < h; ++i)
			cin >> G[i];
			
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				if (G[i][j] == '*' || G[i][j] == 'X')
				{
					cnt = (G[i][j] == '*' ? 0 : 1);
					if (G[i][j] == 'X')
						XColor(i, j);
					dfs(i, j);
					Dots.push_back(cnt);
				}

					
		sort(Dots.begin(), Dots.end());
		cout << "Throw " << ++nr << '\n';
		for (int i = 0; i < Dots.size(); ++i)
			cout << Dots[i] << (i != Dots.size() - 1 ? " " : "\n\n");		
	}	
}
