#include <iostream>
#include <numeric>
using namespace std;

int main()
{
	int s, b, l, r;
	
	while (cin >> s >> b, s && b)
	{
		int L[s], R[s];
		iota(L, L + s, 0);
		iota(R, R + s, 2);
		L[0] = -1;
		R[s - 1] = -1;
		
		for (int i = 0; i < b; ++i)
		{
			cin >> l >> r;
			L[R[r - 1] - 1] = L[l - 1];
			R[L[l - 1] - 1] = R[r - 1];
						
			cout << (L[l - 1] != -1 ? to_string(L[l - 1]) : "*") << ' '
				 << (R[r - 1] != -1 ? to_string(R[r - 1]) : "*") << '\n';
		}
		cout << "-\n";
	}	
}
