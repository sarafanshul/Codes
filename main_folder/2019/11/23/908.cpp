#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
using namespace std;

typedef vector<int> vi;
typedef tuple<int, int, int> iii;
typedef vector<iii> viii;

struct UF
{
	vi p, r;
	UF(int n) : p(n), r(n)
	{
		iota(p.begin(), p.end(), 0);
	}
	
	int f(int i)
	{
		return p[i] == i ? i : p[i] = f(p[i]);
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
	int n, t, a, b, w, case_nr = 0;
	while (cin >> n)
	{
		if (case_nr++)
			cout << '\n';
			
		int old = 0, now = 0;
		UF uf(n);
		
		for (int i = 0; i < n - 1; ++i)
			cin >> a >> b >> w, old += w;
		
		viii E;
		for (int k = 0; k < 2; ++k)
		{
			cin >> t;
			for (int i = 0; i < t; ++i)
			{
				cin >> a >> b >> w;
				E.emplace_back(w, a, b);
			}
		}
		
		sort(E.begin(), E.end());		
		for (auto& e : E)
		{
			tie(w, a, b) = e;
			if (!uf.s(a - 1, b - 1))
				now += w, uf.u(a - 1, b - 1);
		}
		cout << old << '\n' << now << '\n';
	}	
}
