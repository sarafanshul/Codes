#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

typedef pair<int, int> ii;
typedef tuple<int ,int, int> iii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int main()
{
	int t, n, w, v, u;
	cin >> t;
	for (int c_nr = 1; c_nr <= t; ++c_nr)
	{
		cout << "Case " << c_nr << ":\n";
		cin >> n;
		vector<bool> T(n); //Tree
		vvii G(n); 		   //Graph
		priority_queue<iii, vector<iii>, greater<iii> > PQ;
		vector<iii> Res;
		
		string s;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
			{
				cin >> s;
				if (s.back() == ',')
					s.pop_back();
				if (stoi(s))
					G[i].emplace_back(j, stoi(s));
			}
		//Root is 0
		for (int i = 0; i < G[0].size(); ++i)
			PQ.emplace(G[0][i].second, 0, G[0][i].first);
		T[0] = true;
		
		while (!PQ.empty())
		{
			tie (w, v, u) = PQ.top(); PQ.pop();
			if (T[u])	//Lazy deletion
				continue;
							
			T[u] = true;
			for (int i = 0; i < G[u].size(); ++i)				
				if (!T[G[u][i].first])
					PQ.emplace(G[u][i].second, u, G[u][i].first);
				
			Res.emplace_back(w, ::min(v, u), ::max(v, u));
		}
		
		sort(Res.begin(), Res.end());
		for (auto& r : Res)
		{
			tie (w, v, u) = r;
			cout << char(v + 'A') << '-' << char(u + 'A') << ' ' << w << '\n';
		}
	}
}
