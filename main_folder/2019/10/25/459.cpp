#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi G;
vi S;

void dfs(int a)
{
	S[a] = 1;
	for (int k = 0; k < G[a].size(); ++k)
		if (!S[G[a][k]])
			dfs(G[a][k]);
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int cnt = 0;
		string str;
		char m;
		cin >> m;
		cin.ignore();
		G.assign(m - 'A' + 1, vi());
		S.assign(m - 'A' + 1, 0);
		
		while (getline(cin, str), str != "")
		{
			G[str[0] - 'A'].push_back(str[1] - 'A');
			G[str[1] - 'A'].push_back(str[0] - 'A');
		}
		
		for (int i = 0; i < S.size(); ++i)
			if (!S[i])
				++cnt, dfs(i);
				
		cout << cnt << ( T ? "\n\n" : "\n");
	}
}
