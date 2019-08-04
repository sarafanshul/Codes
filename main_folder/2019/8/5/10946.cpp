#include <iostream>
#include <algorithm>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

typedef vector<string> vs;
typedef pair<char, int> ci;
vs G;

int dx[] = {1, 0,  0, -1};
int dy[] = {0, 1, -1,  0};

bool cmp(const ci& a, const ci& b)
{
	return a.second > b.second ? 1 : (a.second == b.second ? a.first < b.first : 0);
}
int dfs(int i, int j, char c)
{
	int area = 1;
	if (i >= 0 && j >= 0 && i < G.size() && j < G[0].size() && G[i][j] == c)
	{
		G[i][j] = '.';
		for (int k = 0; k < 4; ++k)
			area += dfs(i + dx[k], j + dy[k], c);
		return area;		
	}
	return 0;
}

int main()
{
	int rows, cols, problem = 0;
	while (cin >> rows >> cols, rows || cols)
	{
		G.resize(rows);
		vector<ci> H;
		for (int i = 0; i < rows; ++i)
			cin >> G[i];
			
		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < cols; ++j)
				if (G[i][j] != '.')
				{
					char c = G[i][j];
					int cnt = dfs(i, j, c);
					H.emplace_back(c, cnt);
				}
		sort(H.begin(), H.end(), cmp);
		cout << "Problem " << ++problem << ":\n";
		for (auto& elem : H)
			cout << elem.first << ' ' << elem.second << '\n';
	}	
}
