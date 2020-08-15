#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
using namespace std;

typedef vector<int> vi;
typedef tuple<int, int, int> iii;

struct UF
{
	vi p, r;
	UF(int n) : p(n), r(n)
	{
		iota(p.begin(), p.end(), 0);
	}
	
	int f(int x)
	{
		return p[x] == x ? x : p[x] = f(p[x]);
	}
	
	void u(int i, int j)
	{
		int x = f(i), y = f(j);
		if (x == y)
			return;
			
		if (r[x] >= r[y])
		{
			p[y] = x;
			if (r[x] == r[y])
				r[x]++;			
		}
		else
			p[x] = y;
	}
	
	bool s(int i, int j)
	{
		return f(i) == f(j);
	}
};

int main()
{
	int t, m, n;
	cin >> t;
	while (t--)
	{
		int cnt = 0, w, c = 0;
		string s[2];
		cin >> m >> n;
		UF uf(m);
		unordered_map<string, int> M;
		vector<iii> E;
		
		for (int i = 0; i < n; ++i)
		{
			cin >> s[0] >> s[1] >> w;
			for (int k = 0; k < 2; ++k)
				if (M.find(s[k]) == M.end())
					M[s[k]] = cnt++;
			E.emplace_back(w, M[s[0]], M[s[1]]);
		}
		sort(E.begin(), E.end());
		
		for (auto& e : E)
		{
			int a, b;
			tie (w, a, b) = e;
			if (!uf.s(a, b))
				c += w; uf.u(a, b);
		}
		cout << c << ( t > 0 ? "\n\n" : "\n");		
	}
}
