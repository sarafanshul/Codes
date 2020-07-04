#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <tuple>
#include <string>
using namespace std;

typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

void p(priority_queue<ii>& PQ, vvii& G, vb& T, vi& D, int x)
{
	T[x] = true;
	for (auto& elem : G[x])
		if (!T[elem.first] && elem.second > D[elem.first])
		{
			D[elem.first] = elem.second;
			PQ.emplace(elem.second, elem.first);
		}
}

int main()
{
	int n, r, scen = 1;
	while (cin >> n >> r, n || r)
	{
		vvii G(n);
		vb T(n); vi D(n, 0);
		priority_queue<ii> PQ;
		map<string, int> M;
		int cnt = 0, v, w, res = 10001;
		string s[2];
		
		for (int i = 0; i < r; ++i)
		{
			cin >> s[0] >> s[1] >> w;
			for (int k = 0; k < 2; ++k)
				if (M.find(s[k]) == M.end())
					M[s[k]] = cnt++;

			G[M[s[0]]].emplace_back(M[s[1]], w);
			G[M[s[1]]].emplace_back(M[s[0]] , w);			
		}
		
		cin >> s[0] >> s[1];
		PQ.emplace(res, M[s[0]]);
		
		while (!PQ.empty() && !T[M[s[1]]])
		{
			tie(w, v) = PQ.top(); PQ.pop();
			res = min(res, w);
			p(PQ, G, T, D, v);
		}
		
		cout << "Scenario #" << scen++ << '\n' << res << " tons\n\n";
	}
}
