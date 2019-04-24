#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
	int S[4] = {9, 99, 999, 9999};
	int n;
	while (cin >> n)
	{
		vector<long> v;
		for (int i = 0; i <= S[n / 2 - 1]; ++i)
		{
			long x = i * i, d = pow(10, n / 2);				
			long a = x / d, b = x % d;
			if (a + b == i)
				v.push_back(x);
		}
				
		for (long l : v)
			cout << setfill('0') << setw(n) << l << "\n";
	}	
}
