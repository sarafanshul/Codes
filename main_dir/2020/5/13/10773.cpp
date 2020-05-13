#include <iostream>
#include <ios>
#include <cmath>
using namespace std;

int main()
{
	int n, cnt = 0;
	float d, v, u;	
	cin >> n;
	cout.precision(3);
	while (n--)
	{
		cin >> d >> v >> u;
		if (u <= v || !u || !v)
			cout << "Case " << ++cnt << ": "  << "can't determine\n";
		else
		{
			float t1 = d / sqrt(u*u - v*v);
			float t2 = sqrt(d*d + d*d*v*v/(u*u)) / sqrt(u*u + v*v);
			cout << fixed << "Case " << ++cnt << ": " << t1 - t2 << '\n';
		}
	}
}
