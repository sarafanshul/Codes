#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

bool ap(vvi& G, vvi& R, vi& P, int s, int t)
{
	queue<int> Q;
	Q.push(s);
	while (!Q.empty())
	{
		int u = Q.front(); Q.pop();
		
		if (u == t)
			return true;
		
		for (int i = 0; i < G.size(); ++i)
			if (P[i] == -1 && G[u][i] && R[u][i])
				P[i] = u, Q.push(i);
	}
	
	return false;
}

int main()
{
	int n, s, t, c, u, v, w, cnt = 1;
	while (cin >> n, n)
	{
		vvi G(n, vi(n, 0)), R(n, vi(n, 0));
		cin >> s >> t >> c;
		for (int i = 0; i < c; ++i)
		{
			cin >> u >> v >> w;
			G[u - 1][v - 1] = G[v - 1][u - 1] = 1;
			R[u - 1][v - 1] += w;
			R[v - 1][u - 1] += w;
		}
		
		int flow = 0;
		vi P(n, -1);
		
		while (ap(G, R, P, s - 1, t - 1))
		{
			int aug = 1000;
			for (int it = t - 1; it != s - 1; it = P[it])
				aug = ::min(aug, R[P[it]][it]);
			
			for (int it = t - 1; it != s - 1; it = P[it])
				R[P[it]][it] -= aug, R[it][P[it]] += aug;
				
			flow += aug;
			
			P.assign(n, -1);
		}
		
		cout << "Network " << cnt++ << "\nThe bandwidth is " << flow << ".\n\n";
	}
}
