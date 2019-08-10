#include <iostream>
#include <functional>
#include <climits>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main()
{
	int T, n, e, t, m, a, b, c;
	cin >> T;
	while (T--)
	{
		cin >> n >> e >> t >> m;
		vector<vii> G(n);
		for (int i = 0; i < m; ++i)
		{	//Having SSSP to destination, we have to flip edges
			cin >> a >> b >> c;
			G[b - 1].emplace_back(a - 1, c);
		}
		
		vi D(n, INT_MAX); 
		D[e - 1] = 0;
		priority_queue<ii, vector<ii>, greater<ii> > PQ;
		PQ.emplace(0, e - 1);
		while (!PQ.empty())
		{
			tie(c, a) = PQ.top(); PQ.pop();
			if (c > D[a])
				continue;
			
			for (int i = 0; i < G[a].size(); ++i)
				if (c + G[a][i].second < D[G[a][i].first])
				{
					D[G[a][i].first] = c + G[a][i].second;
					PQ.emplace(D[G[a][i].first], G[a][i].first);
				}
		}
		
		int res = 0;
		for (int i : D)
			if (i <= t)
				++res;
		
		cout << res << (T > 0 ? "\n\n" : "\n");
	}
}
