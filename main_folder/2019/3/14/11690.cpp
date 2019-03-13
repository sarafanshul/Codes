#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

typedef vector<int> vi;

struct UF
{
	vi r, p;
	UF (int n) : r(n), p(n)
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
};


int main()
{
	int T, n, m, a, b;
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		UF uf(n);
		vi A(n);
		for (int i = 0; i < n; ++i)
			cin >> A[i];
				
		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b;
			uf.u(a, b);
		}
		
		vector<int> M(n);
		for (int i = 0; i < n; ++i)
			M[uf.f(i)] += A[i];
		
		cout << (all_of(M.begin(), M.end(), [&](int x){return x == 0;}) ? "POSSIBLE\n" : "IMPOSSIBLE\n");
	}
}
