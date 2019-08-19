#include <iostream>
#include <string>

using namespace std;

int main()
{
	string M[2][2] = {{"SO", "NO"},{"SE", "NE"}};
	
	int k;
	while (cin >> k, k > 0)
	{
		int p, q, m, n;
		cin >> p >> q;
		
		for (int i = 0; i < k; ++i)
		{
			cin >> m >> n;
			if ((m != p) && (n != q))
				cout << M[m > p][n > q] << "\n";
			else
				cout << "divisa\n";
		}			
	}
	return 0;
}
