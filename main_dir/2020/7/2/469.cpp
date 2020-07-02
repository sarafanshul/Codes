#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

typedef vector<string> vs;
vs G; //Graph
vs S; //Seen

int dx[] = {1, 1,  1, 0,  0, -1, -1, -1};
int dy[] = {1, 0, -1, 1, -1,  1,  0, -1};

int dfs(int x, int y)
{			
	int area = 1;
	S[x][y] = '1';
	for (int i = 0; i < 8; ++i)
	{
		int xx = x + dx[i], yy = y + dy[i];
		if (xx >= 0 && xx < G.size() && yy >= 0 && yy < G[0].size() && S[xx][yy] == '0')
			if (G[xx][yy] == 'W')
				area += dfs(xx, yy);
			else
				S[xx][yy] = '1';
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
		G.clear();
		string str;
		while (getline(cin, str), str[0] == 'L' || str[0] == 'W')
			G.push_back(str);
			
		while (str != "")
		{
			S.assign(G.size(), string(G[0].size(), '0'));
			istringstream iss(str);
			int x, y;
			iss >> x >> y;
			x -= 1; y -= 1;			
			cout << (G[x][y] == 'W' ? dfs (x, y) : 0) << '\n';
			getline(cin, str);
		}
		cout << (T ? "\n" : "");
	}
}
