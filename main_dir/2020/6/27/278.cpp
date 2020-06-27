#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		char p;
		int m, n;
		cin >> p >> m >> n;
		if (p == 'r' || p == 'Q')
			cout << min(m,n) << "\n";
		else if (p == 'k')
			cout << ceil(m * n / 2.0) << "\n";
		else if (p == 'K') 
			cout << ceil(m / 2.0) * ceil(n / 2.0) << "\n";		
	}	
}
