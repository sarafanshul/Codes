#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
using namespace std;

typedef vector<int> vi;
typedef tuple<int, int, int> iii;

struct UF
{
	vi r, p;
	int sets;
	UF(int n) : p(n), r(n), sets(n)
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
		--sets;
			
		if (r[x] >= r[y])
		{
			p[y] = x;
			if (r[x] == r[y])
			r[x]++;
		}
		else
			p[x] = y;
	}
	
	bool s(int x, int y)
	{
		return f(x) == f(y);
	}
};

int main()
{
	int s, c, p;
	while (cin >> s >> c, s || c)
	{
		int cm = 0;
		UF uf(s);
		vector<iii> E(c);
		unordered_map<string, int> M;
		string str, tmp;
		for (int i = 0; i < s; ++i)
			cin >> str,	M[str] = i;
		
		for (int i = 0; i < c; ++i)
		{
			cin >> str >> tmp >> p;
			E[i] = tie(p, M[str], M[tmp]);
		}
		sort(E.begin(), E.end());
		
		cin >> str;
		for (auto& e : E)
		{
			int x, y;
			tie(p, x, y) = e;
			if (!uf.s(x, y))
				cm += p, uf.u(x, y);
		}
		
		cout << (uf.sets > 1 ? "Impossible\n" : to_string(cm) + "\n");
	}
}
