#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<string> vs;
vs M;

int dx[] = {1, 0,  0, -1};
int dy[] = {0, 1, -1,  0};

void dfs(int y, int x)
{
	if (y >= 0 && x >= 0 && y < M.size() && x < M[0].size() && M[y][x] == ' ' || M[y][x] == '*')
	{
		M[y][x] = '#';
		for (int i = 0; i < 4; ++i)
			dfs(y + dy[i], x + dx[i]);
		
	}
}

int main()
{
	int T;
	cin >> T;
	cin.ignore();
	while (T--)
	{
		M.clear();
		int y, x;
		string s;
		while (getline(cin, s), s[0] != '_')
		{
			M.push_back(s);
			int f = s.find('*');
			if (f != -1)
				x = f, y = M.size() - 1;
		}
		
		dfs(y, x);
		for (string& str : M)
			cout << str << '\n';
		cout << s << '\n';
	}
}
