#include <iostream>
using namespace std;

int main()
{
	int n, b, h, w;
	while (cin >> n >> b >> h >> w)
	{
		int total = b + 1;
		for (int i = 0; i < h; ++i)
		{
			int p, nr, max = 0;
			cin >> p;
			for (int j = 0; j < w; ++j)
			{
				cin >> nr;
				if (nr > max)
					max = nr;
			}		
				
			if (max >= n && p * n < total)
				total = n * p;				
		}
		if (total < b + 1)
			cout << total << "\n";
		else
			cout << "stay home\n";		
	}
	
	return 0;
}
