#include <iostream>
#include <map>
#include <string>
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
	int a, r;
	while (cin >> a >> r, a || r)
	{
		UF uf(a);
		map<string, int> M;
		string s, t;
		for (int i = 0; i < a; ++i)
			cin >> s, M[s] = i;
		
		for (int i = 0; i < r; ++i)
		{
			cin >> s >> t;
			uf.u(M[s], M[t]);
		}
		cout << uf.m << '\n';
	}	
}
