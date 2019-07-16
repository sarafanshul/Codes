#include <iostream>
using namespace std;

int main()
{
	int n, m, q, cnt = 1;
	while (cin >> n, n)
	{
		cout << "Case " << cnt++ << ":\n";
		int A[1000];
		for (int i = 0; i < n; ++i)
			cin >> A[i];
		
		cin >> m;
		for (int i = 0; i < m; ++i)
		{
			cin >> q;
			unsigned min = -1, res = -1;
			
			for (int x = 0; x < n; ++x)
				for (int y = x + 1; y < n; ++y)
					if (std::abs(A[x] + A[y] - q) < min)
					{
						min = std::abs(A[x] + A[y] - q);
						res = A[x] + A[y];
					}
			
			cout << "Closest sum to " << q << " is " << res << ".\n";
		}
	}
}
