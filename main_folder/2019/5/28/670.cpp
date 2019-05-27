#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>

using namespace std;
typedef vector<int> vi;
typedef vector<std::pair<int, int> > vii;
typedef vector<vi> vvi;

bool ap(vvi& G, vi& M, vi& V, int u)
{
	if (V[u])
		return false;
	
	V[u] = 1;
	
	for (int i = 0; i < G[u].size(); ++i)
		if (G[u][i] && (M[i] == -1 || ap(G, M, V, M[i])))
		{
			M[i] = u;
			return true;
		}
	
	return false;
}

int main()
{
	int T, n, m, x, y;
	cin >> T;
	
	while (T--)
	{
		cin >> n >> m;
		vii B, R;
		vvi G(n - 1, vi(m));
		for (int i = 0; i < n; ++i)
		{
			cin >> x >> y;
			B.emplace_back(x, y);
		}
		
		for (int i = 0; i < m; ++i)
		{
			cin >> x >> y;
			R.emplace_back(x, y);
		}
		
		for (int i = 0; i < n - 1; ++i)
		{
			float l = hypotf(B[i].first - B[i + 1].first, B[i].second - B[i + 1].second);
			for (int j = 0; j < m; ++j)
			{
				float d = hypot(B[i].first - R[j].first, B[i].second - R[j].second) + 
						  hypot(B[i + 1].first - R[j].first, B[i + 1].second - R[j].second);
				G[i][j] = d <= 2 * l ? 1 : 0;				
			}
		}
		
		int MCBM = 0;
		vi M(m, -1);
		for (int i = 0; i < n - 1; ++i)
		{
			vi V(n - 1, 0);
			MCBM += ap(G, M, V, i);
		}
		
		vi ind(n, -1);
		for (int i = 0; i < m; ++i)
			if (M[i] >= 0)
				ind[M[i]] = i;
		
		cout << n + MCBM << "\n";
		for (int i = 0; i < n - 1; ++i)
		{
			cout << B[i].first << " " << B[i].second << " ";
			if(ind[i] >= 0)
				cout << R[ind[i]].first << " " << R[ind[i]].second << " ";
		}
		cout << B[n - 1].first << " " << B[n - 1].second << "\n";
			
		if (T > 0)
			cout << "\n";
	}
}
