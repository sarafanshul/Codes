#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[] = {2,  2, -2, -2, 1, -1,  -1,  1};
int dy[] = {1, -1,  1, -1, 2,  2,  -2, -2};

int main()
{
	string st, end;	
	while (cin >> st >> end)
	{
		string G[8](string(8, '0' - 1));
		int x = st[0] - 'a', y = st[1] - '1';
		G[y][x] = '0';
		queue<pair<int, int> > Q;
		Q.emplace(y, x);
		
		while (!Q.empty())
		{
			tie(y, x) = Q.front();
			Q.pop();
			
			for (int i = 0; i < 8; ++i)
			{
				int xx = x + dx[i], yy = y + dy[i];
				if (xx >= 0 && yy >= 0 && xx < 8 && yy < 8 && G[yy][xx] == '0' - 1)
				{
					Q.emplace(yy, xx);
					G[yy][xx] = G[y][x] + 1;
				}
			}
		}
		cout << "To get from " << st << " to " << end << " takes " << G[end[1] - '1'][end[0] - 'a'] << " knight moves.\n";		
	}
}
