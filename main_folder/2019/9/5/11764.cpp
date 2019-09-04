#include <iostream>
using namespace std;

int main()
{
	int T, cnt = 1;
	cin >> T;
	while (T--)
	{
		int n, W[50], low = 0, high = 0;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> W[i];
		for (int i = 1; i < n; ++i)
		{
			if (W[i] > W[i - 1])
				high++;
			else if (W[i] < W[i - 1])
				low++;
		}
		cout << "Case " << cnt++ << ": " << high << " " << low << "\n";
	}
	
	return 0;
}
