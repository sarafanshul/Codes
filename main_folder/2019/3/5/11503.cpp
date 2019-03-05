#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

typedef vector<int> vi;

struct UF
{
	vi p, r, s;
	UF(int n) : p(n), r(n), s(n, 1)
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
	int T, F;
	cin >> T;
	while (T--)
	{
		UF uf(200000);
		unordered_map<string, int> M;
		int cnt = 1; //Map the names to 1..200000
		cin >> F;
		for (int i = 0; i < F; ++i)
		{
			string s[2];
			cin >> s[0] >> s[1];
			for (int k = 0; k < 2; ++k)
				if (M[s[k]] == 0)
					M[s[k]] = cnt++;
			
			uf.u(M[s[0]] - 1, M[s[1]] - 1);
			cout << uf.s[uf.f(M[s[0]] - 1)] << '\n';
		}
	}	
}
