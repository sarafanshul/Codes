#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int b, n;
	while (cin >> b >> n, b || n)
	{
		int R[21];
		
		for (int i = 0; i < b; ++i)
			cin >> R[i];
			
		for (int i = 0; i < n; ++i)
		{
			int x, y, z;
			cin >> x >> y >> z;
			R[--x] -= z;
			R[--y] += z;			 
		}
		
		if (all_of(R, R + b, [](int x){return x >= 0;}))
			cout << "S\n";
		else
			cout << "N\n";
	}
}
