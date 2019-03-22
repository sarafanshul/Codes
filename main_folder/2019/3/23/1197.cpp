#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

typedef vector<int> vi;

struct UF
{
	vi r, p, s;
	UF(int n) : r(n), p(n), s(n, 1)
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
			s[x] += s[y];
			if (r[x] == r[y])
				r[x]++;
		}
		else
		{
			p[x] = y;
			s[y] += s[x];
		}
	}
};

int main()
{
	int n, m, k;
	while (cin >> n >> m, n || m)
	{
		UF uf(n);
		int cnt = 0;
		for (int i = 0; i < m; ++i)
		{
			cin >> k;
			vi gr(k);
			for (int j = 0; j < k; ++j)
				cin >> gr[j];
				
			for (int elem : gr)
				uf.u(gr[0], elem);
		}
				
		cout << uf.s[uf.f(0)] << '\n';
	}
}
