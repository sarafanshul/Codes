#include <iostream>
#include <cstring>
#include <bitset>
using namespace std;

int main()
{
	int n, m, c, cnt = 1;
	while (cin >> n >> m >> c, n || m || c)
	{
		bool flag = false;
		int N[20], now = 0, max = 0;
		memset(N, 0, 20 * sizeof(int));
		bitset<32> sw(0);
		
		for (int i = 0; i < n; ++i)
			cin >> N[i];
		for (int i = 0; i < m; ++i)
		{			
			int x;
			cin >> x;
			x--;
			sw.flip(x);
			if (sw[x] == 1)
				now += N[x];
			else
				now -= N[x];
				
			if (now > max)
				max = now;
				
			if (max > c)
				flag = true;
		}	
		
		cout << "Sequence " << cnt++ << "\nFuse was ";
		if (flag)
			cout << "blown.\n\n";
		else
			cout << "not blown.\nMaximal power consumption was " << max << " amperes.\n\n" ;
	}
	
	return 0;
}
