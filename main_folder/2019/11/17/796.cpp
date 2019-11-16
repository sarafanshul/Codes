#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <string>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
vector<vi> G;
vector<ii> aB;
vi num, low, p;
int cnt;

void artB(int u)
{
	low[u] = num[u] = cnt++;
	for (int i = 0; i < G[u].size(); ++i)
	{
		int w = G[u][i];		
		if (num[w] == -1)
		{
			p[w] = u;			
			artB(w);
			
			if (low[w] > num[u])
				aB.push_back(minmax(u, w));
			low[u] = ::min(low[u], low[w]);
		}
		else if (p[u] != w)
			low[u] = ::min(low[u], num[w]);
	}
}

int main()
{
	int n, u, v, m;
	string s;
	while (cin >> n)
	{
		G.assign(n, vi()); aB.clear();
		num.assign(n, -1); low.assign(n, -1); p.assign(n, -1);
		for (int i = 0; i < n; ++i)
		{
			cin >> u >> s;
			m = stoi(string(s.begin() + 1, s.end() - 1));
			for (int j = 0; j < m; ++j)
			{
				cin >> v;
				G[u].push_back(v);
				G[v].push_back(u);
			}			
		}
		
		//Articulation bridges
		cnt = 0;
		for (int i = 0; i < n; ++i)
			if (num[i] == -1)
				artB(i);
		
		cout << aB.size() << " critical links\n";
		sort(aB.begin(), aB.end());
		for (auto& el : aB)
			cout << el.first << " - " << el.second << "\n";
		cout << "\n";
	}
}
