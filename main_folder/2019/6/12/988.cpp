#include <iostream>
#include <stack>
#include <vector>
using namespace std;

typedef vector<int> vi;

void dfs(int k, vector<vi>& G, vi& V, stack<int>& S)
{
	V[k] = 1;
	for (int i = 0; i < G[k].size(); ++i)
		if (!V[G[k][i]])
			dfs(G[k][i], G, V, S);
	
	S.push(k);
}

int main()
{
	int n, m;
	while (cin >> n)
	{
		vector<vi> G(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> m;
			G[i].resize(m);
			for (int j = 0; j < m; ++j)
				cin >> G[i][j];
		}
		
		stack<int> S;
		vi V(n);			// Visited
		dfs(0, G, V, S);
		
		V.assign(n, 0);		// Distance
		V[0] = 1;
		while (!S.empty())
		{
			m = S.top(); S.pop();
			for (int i = 0; i < G[m].size(); ++i)
				V[G[m][i]] += V[m];			
		}
		
		int paths = 0;
		for (int i = 0; i < n; ++i)
			if (!G[i].size())	//No out-degree
				paths += V[i];
				
		cin >> ws;
		cout << paths << (cin.peek() == EOF ? "\n" : "\n\n");
	}
}
