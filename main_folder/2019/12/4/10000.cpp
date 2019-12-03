#include <iostream>
#include <vector>
#include <stack>
#include <tuple>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
vvi G;
vi V;
stack<int> S;

void dfs(int i)
{
	V[i] = 1;
	for (int k = 0; k < G[i].size(); ++k)
		if (!V[G[i][k]])
			dfs(G[i][k]);
	
	S.push(i);
}

int main()
{
	int n, s, p, q, cnt = 0;
	while (cin >> n, n)
	{
		G.assign(n, vi());
		V.assign(n, 0);
		cin >> s;
		while (cin >> p >> q, p || q)
			G[p - 1].push_back(q - 1);
		
		dfs(s - 1);
		vi D(n, 0);
		int m = 0, ind = s - 1;
		while (!S.empty())
		{
			p = S.top(); S.pop();
			for (int i = 0; i < G[p].size(); ++i)
				if (D[p] + 1 > D[G[p][i]])
				{
					D[G[p][i]] = D[p] + 1;
					if (m == D[p] + 1)
						ind = ::min(ind, G[p][i]);
					else if (m < D[p] + 1)
						m = D[p] + 1, ind = G[p][i];
				}
		}
		cout << "Case " << ++cnt << ": The longest path from " << s 
			 << " has length " << m << ", finishing at " << ind + 1 << ".\n\n";
	}
}
