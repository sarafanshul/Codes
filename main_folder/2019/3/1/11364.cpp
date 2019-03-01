#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		unsigned n, a, min = -1, max = 0;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> a;
			if (a < min)
				min = a;
			if (a > max)
				max = a;
		}		
		cout << 2 * (max - min) << "\n";		
	}
}
