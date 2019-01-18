#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
using namespace std;

typedef vector<string> vs;
typedef pair<char, int> ci;
vs G;

int da[] = {1, 0,  0, -1};
int db[] = {0, 1, -1,  0};

bool cmp(const ci& a, const ci& b)
{
	return a.second > b.second ? 1 : (a.second == b.second ? a.first < b.first : 0);
}

void dfs(int a, int b, char t)
{
	if (a >= 0 && b >= 0 && a < G.size() && b < G[0].size() && G[a][b] == t)
	{
		G[a][b] = '.';
		for (int i = 0; i < 4; ++i)
			dfs(a + da[i], b + db[i], t);
	}
}

int main()
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i)
	{
		int h, w;
		cin >> h >> w;
		G.assign(h, string());
		for (int k = 0; k < h; ++k)
			cin >> G[k];
			
		vector<ci> Res;
		for (int l = 0; l < 26; ++l)
			Res.emplace_back(char('a' + l), 0);
		
		
		for (int k = 0; k < h; ++k)
			for (int l = 0; l < w; ++l)
			{
				if (G[k][l] != '.')
				{
					Res[G[k][l] - 'a'].second++;
					dfs(k, l, G[k][l]);
				}
			}
			
		sort(Res.begin(), Res.end(), cmp);
		cout << "World #" << i << '\n';
		for (auto& elem : Res)
			if (elem.second)
				cout << elem.first << ": " << elem.second << '\n';
	}
}
