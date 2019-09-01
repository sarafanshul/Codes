#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <string>
using namespace std;

typedef vector<int> vi;
vector<vi> E, rE;
vector<bool> V;
unordered_map<string, int> M;
int size;
stack<int> S;

void Kosaraju(int u, bool pass = 0)
{
	V[u] = true;
	
	vi adj = (pass ? rE[u] : E[u]);
	for (int i = 0; i < adj.size(); ++i)
		if (!V[adj[i]])
			Kosaraju(adj[i], pass);
	
	if (!pass)
		S.push(u);
}


int main()
{
	int n, m;
	string s, t;
	while (cin >> n >> m, n || m)
	{
		cin.ignore();
		size = 1; M.clear();
		E.assign(n, vi());
		rE.assign(n, vi());
				
		for (int i = 0; i < n; ++i)
			getline(cin, s), M[s] = i;
		
		for (int i = 0; i < m; ++i)
		{
			getline(cin, s); getline(cin, t);
			int x = M[s], y = M[t];
			E[x].push_back(y);
			rE[y].push_back(x);	
		}
		
		V.assign(n, false);
		for (int i = 0; i < n; ++i)
			if (!V[i])
				Kosaraju(i);
		
		V.assign(n, false);
		int SCC = 0;
		while (!S.empty())
		{
			int t = S.top(); S.pop();
			if (!V[t])
				++SCC, Kosaraju(t, true);
		}
		
		cout << SCC << endl;
	}
}

