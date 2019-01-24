#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

typedef vector<int> vi;

struct UF
{
	vi r, p, s;
	int m;
	UF(int n) : r(n), p(n), s(n, 1), m(1)
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
			m = ::max(m, s[x]);
			if (r[x] == r[y])
				r[x]++;
		}
		else
		{
			p[x] = y;
			s[y] += s[x];
			m = ::max(m, s[y]);
		}
	}	
};

int main()
{
	int T;
	cin >> T;
	int n, m, x, y;
	while (T--)
	{
		cin >> n >> m;
		UF uf(n);
		for (int i = 0; i < m; ++i)
		{
			cin >> x >> y;
			uf.u(x - 1, y - 1);
		}
		cout << uf.m << '\n';
	}
}
