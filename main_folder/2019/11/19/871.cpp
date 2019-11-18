#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<string> vs;
vs G, S;
int M;

int dx[] = {1,  1, 1, 0,  0, -1, -1, -1};
int dy[] = {0, -1, 1, 1, -1,  0, -1,  1};

int dfs(int x, int y)
{	
	S[x][y] = 1;
	int area = 1;
	for (int i = 0; i < 8; ++i)
	{
		int xx = x + dx[i], yy = y + dy[i];
		if (xx >= 0 && yy >= 0 && xx < G.size() && yy < G[0].size() && !S[xx][yy] && G[xx][yy] == '1')
			area += dfs(xx, yy);
	}	
	return area;
}

int main()
{
	int T;
	cin >> T;
	cin.ignore(2);
	while (T--)
	{
		M = 0;
		G.clear();
		string str;
		
		while (getline(cin, str), str != "")
			G.push_back(str);
		S.assign(G.size(), string(G[0].size(), 0));
			
		for (int i = 0; i < G.size(); ++i)
			for (int j = 0; j < G[0].size(); ++j)
				if (!S[i][j] && G[i][j] == '1')
					M = max(dfs(i, j), M);
			
		cout << M << (T ? "\n\n" : "\n");
	}	
}
