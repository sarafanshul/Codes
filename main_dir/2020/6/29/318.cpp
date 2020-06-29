#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
#include <algorithm>
#include <iterator>
#include <functional>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main()
{
	cout.precision(1);
	int n, m, a, b, l, sys = 1;
	while (cin >> n >> m, n || m)
	{
		vector<vii> G(n);
		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b >> l;
			G[a - 1].emplace_back(b - 1, l);
			G[b - 1].emplace_back(a - 1, l);
		}
		
		vi D(n, INT_MAX); //Distances to source
		D[0] = 0;
		priority_queue<ii, vector<ii>, greater<ii> > PQ;
		PQ.emplace(0, 0);
		while (!PQ.empty())
		{
			tie(l, a) = PQ.top(); PQ.pop();
			if (l > D[a])
				continue;
				
			for (int i = 0; i < G[a].size(); ++i)
				if (D[a] + G[a][i].second < D[G[a][i].first])
				{
					D[G[a][i].first] = l + G[a][i].second;
					PQ.emplace(l + G[a][i].second, G[a][i].first);
				}
		}
		
		auto it = max_element(D.begin(), D.end());
		int ind = distance(D.begin(), it), adj = 0;
		float time = D[ind];

		//Check if any row is still falling
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < G[i].size(); ++j)
			{
				tie(b, l) = G[i][j];
				float diff = (l - ::abs(D[i] - D[b])) / 2.0;
				if (::max(D[i], D[b]) + diff > time)
				{
					time = ::max(D[i], D[b]) + diff;
					tie(ind, adj) = minmax(i, b);
				}
			}
			

		cout << "System #" << sys++ << "\nThe last domino falls after "	<< fixed << time << " seconds, ";
		if (adj > 0)
			cout << "between key dominoes " << ind + 1 << " and " << adj + 1 << ".\n\n";
		else
			cout << "at key domino " << ind + 1 << ".\n\n";
	}
}
