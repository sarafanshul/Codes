#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;
typedef vector<int> vi;

struct UF
{
	vi r, p;
	UF(int n) : r(n), p(n)
	{
		iota(p.begin(), p.end(), 0);
	}
	int f(int x)
	{
		return (p[x] == x ? x : p[x] = f(p[x]));
	}
	
	void u(int i, int j)
	{
		int x = f(i), y = f(j);
		if (x == y)
			return;
			
		if (r[x] <= r[y])
		{
			p[x] = y;
			if (r[x] == r[y])
				r[y]++;
		}
		else
			p[y] = x;
	}
	
	bool s(int x, int y)
	{
		return f(x) == f(y);
	}
	
};

int main()
{
	int T;
	cin >> T;
	
	while (T--)
	{
		int n, res[2] = {};
		cin >> n;
		cin.ignore();
		UF uf(n);
		string s;
		while (getline(cin, s), s != "")
		{
			istringstream iss(s);
			char c; int i, j;
			iss >> c >> i >> j;
			if (c == 'c')
				uf.u(i - 1, j - 1);
			else
				res[uf.s(i - 1, j - 1)]++;
		}
		cout << res[1] << ',' << res[0] << (T > 0 ? "\n\n" : "\n");		
	}	
}
