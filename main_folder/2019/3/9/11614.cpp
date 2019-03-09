#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	long q;
	cin >> n;
	while (n--)
	{
		cin >> q;
		double key = sqrt(2) * sqrt(q);
		long n_low = floor(key - 2), n_hi = ceil(key);
		
		for (long j = n_low; j <= n_hi; ++j)
		{
			long long low = j * (j + 1) / 2, up = (j + 1) * (j + 2) / 2;
			if (low <= q && q < up)
				cout << j << '\n';		
		}
	}
}
