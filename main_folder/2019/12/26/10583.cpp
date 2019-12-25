#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

typedef vector<int> vi;

struct UF
{
	vi r, p;
	int sets;
	UF(int n) : r(n), p(n), sets(n)
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
		--sets;
		
		if (r[x] >= r[y])
		{
			p[y] = x;
			if (r[y] == r[x])
				r[x]++;
		}
		else
			p[x] = y;
	}	
};

int main()
{
	int n, m, i, j, case_nr = 0;
	while (cin >> n >> m, n || m)
	{
		UF uf(n);
		for (int k = 0; k < m; ++k)
		{
			cin >> i >> j;
			uf.u(i - 1, j - 1);
		}
		cout << "Case " << ++case_nr << ": " << uf.sets << '\n';		
	}	
}
