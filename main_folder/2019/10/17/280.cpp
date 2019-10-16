#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi G;
vi Seen;

void dfs(int a)
{
	for (int b : G[a])
		if (!Seen[b])
		{
			Seen[b] = 1;
			dfs(b);
		}
}

int main()
{
	int n, v, u;
	while (cin >> n, cin.ignore(), n)
	{
		G.assign(n, vi());
		string s;
		while (getline(cin, s), s != "0")
		{
			istringstream iss(s);
			iss >> v;
			while (iss >> u, u)
				G[v - 1].push_back(u - 1);
		}
		
		cin >> u;
		for (int i = 0; i < u; ++i)
		{
			Seen.assign(n, 0);
			cin >> v;
			dfs(v - 1);
			cout << count(Seen.begin(), Seen.end(), 0);
			for (int j = 0; j < Seen.size(); ++j)
				if (!Seen[j])
					cout << ' ' << j + 1;
			cout << '\n';
		}
	}	
}
