#include <iostream>
#include <tuple>
#include <vector>
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
	int n, m, x, y, z;
	while (cin >> n >> m, n || m)
	{
		int cm = 0, co = 0;
		UF uf(n);
		vector<iii> E(m);
		for (int i = 0; i < m; ++i)
		{
			cin >> x >> y >> z;
			E[i] = tie(z, x, y);
			co += z;
		}
		
		sort(E.begin(), E.end());
		for (auto& e : E)
		{
			tie(z, x, y) = e;
			if (!uf.s(x, y))
				cm += z, uf.u(x, y);
		}		
		
		cout << co - cm << '\n';
	}
}
