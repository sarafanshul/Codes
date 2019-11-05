#include <iostream>
using namespace std;

int main()
{
	int n, cnt = 0;
	while (cin >> n, n != 0)
	{
		int sigma = 0, A[n], res = 0;
		for (int i = 0; i < n; ++i)
		{
				cin >> A[i];
				sigma += A[i];
		}
		int mean = sigma / n;
		for (int a : A)
			if (a > mean)
				res += a - mean;
				
		cout << "Set #" << ++cnt << "\nThe minimum number of moves is " << res << ".\n\n";
	}
}
