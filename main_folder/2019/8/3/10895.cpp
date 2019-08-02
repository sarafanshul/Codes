#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int main()
{
	int n, m, r;
	while (cin >> n >> m)
	{
		vector<vector<pair<int, int> > > T(m);
		for (int i = 0; i < n; ++i)
		{
			cin >> r;
			vector<int> I(r), E(r);
			for (int j = 0; j < r; ++j) cin >> I[j];
			for (int j = 0; j < r; ++j) cin >> E[j];
			for (int j = 0; j < r; ++j)
				T[I[j] - 1].emplace_back(i, E[j]);			
		}
		
		cout << m << ' ' << n << '\n';
		for (int i = 0; i < m; ++i)
		{
			cout << T[i].size();
			for (auto& elem : T[i])
				cout << ' ' << elem.first + 1;
			cout << '\n';
			for (int j = 0; j < T[i].size(); ++j)
				cout << T[i][j].second << (j == T[i].size() - 1 ? "" : " ");
			cout << '\n';
		}
	}
}
