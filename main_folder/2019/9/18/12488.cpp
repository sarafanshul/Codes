#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int S[24], E[24], P[24];
		for (int i = 0; i < n; ++i)
			cin >> S[i];
			
		for (int i = 0; i < n; ++i)
			cin >> E[i];
			
		iota(P, P + n, 0);
		sort(P, P + n, [&](int i, int j){return S[i] < S[j];});		
		
		int res = 0;
		for (int i = 0; i < n; ++i)
		{			
			res += count_if(S, S + P[E[i] - 1], [&](int x){return x >= 0;});
			S[P[E[i] - 1]] = -1;			
		}
		
		cout << res << "\n";
	}
}
