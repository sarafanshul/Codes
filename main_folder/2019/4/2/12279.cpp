#include <iostream>

using namespace std;

int main()
{
	int n, cnt = 0;
	while (cin >> n, n != 0)
	{
		int N[2] = {0, 0};
		for (int i = 0; i < n; ++i)
		{
			int x;
			cin >> x;
			N[x == 0]++;
		}
		cout << "Case " << ++cnt << ": " << N[0] - N[1] << "\n";
	}
	
	return 0;
}
