#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a; long p;
	while (cin >> a >> p, a && p)
	{
		int n_max = (a + 1) / 2;
		//Pronaci n:= pojas u kojem je p
		int n_low = sqrt((p - 1.0) / 4) - 1, n = -1;
		for (int i = n_low; i <= n_max; ++i)
			if (p <= 1 + (long)4 * i * (i + 1) && n == -1)
				n = i;				

		
		if (n == 0)
		{
			cout << "Line = " << n_max << ", column = " << n_max << ".\n";
			continue;
		}
						
		long start = 2 + (long)4 * n * (n - 1);
		long end = 1 + (long)4 * n * (n + 1);
		long side = (p - start) / (2 * n); // 0 = U; 1 = L; 2 = D; 3 = R
		long pos = (p - start) % (2 * n);
		
		long y[4] = {n_max + n, a - pos - n_max + n, n_max - n, pos + n_max - n + 1};
		long x[4] = {a - pos - n_max + n, n_max - n, pos + n_max - n + 1, n_max + n};
		
		cout << "Line = " << y[side] << ", column = " << x[side] << ".\n";
	}
}
