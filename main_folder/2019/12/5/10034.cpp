#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

typedef vector<int> vi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;

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

double d(dd a, dd b)
{
	double x = a.first - b.first, y = a.second - b.second;
	return sqrt(x * x + y * y);
}

int main()
{
	int t, n, i, j;
	cin >> t;
	while (t--)
	{
		cin >> n;
		double a, b, res = 0;
		vdd Pts;
		for (int i = 0; i < n; ++i)
		{
			cin >> a >> b;
			Pts.emplace_back(a, b);
		}
		
		vector<tuple<double, int, int> > E;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				E.emplace_back(d(Pts[i], Pts[j]), i, j);
		
		sort(E.begin(), E.end());
		UF uf(n);
		for (auto& e : E)
		{
			tie(a, i, j) = e;
			if (!uf.s(i, j))
			{
				uf.u(i, j);
				res += a;
			}
		}

		printf("%.2f\n", res);
		if (t > 0) 
			printf("\n");		
	}	
}
