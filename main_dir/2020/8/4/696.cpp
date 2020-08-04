#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int m, n, res;
	while (cin >> m >> n, n || m)
	{
		int dim[2] = {m, n};
		if (m > n)
			swap (m, n);
		if (m == 1)
			res = n;
		else if (m == 2)
			res = (n % 4 == 1 ? n + 1 : ((n -1) / 4 + 1)* 4);
		else 
			res = ceil(m * n / 2.0);
		cout << res << " knights may be placed on a " << dim[0] << " row " << dim[1] << " column board.\n";
	}	
}
