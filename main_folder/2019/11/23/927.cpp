#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int n, len, d, k;
	cin >> n;
	
	while (n--)
	{
		cin >> len;
		vector<int> A(len + 1);
		for (int i = 0; i <= len; ++i)
			cin >> A[i];
		
		cin >> d >> k;
		int x = 1;
		long res = 0;
		while (k > d * x * (x + 1) * .5)
			++x;

		for (int i = 0; i <= len; ++i)
			res += A[i] * pow(x, i);
		
		cout << res << "\n";
	}	
}
