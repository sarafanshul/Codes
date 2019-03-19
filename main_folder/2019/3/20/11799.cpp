#include <iostream>
using namespace std;

int main()
{
	int T, cnt = 0;
	cin >> T;
	while (T--)
	{
		int N, a, max = 0;
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			cin >> a;
			if (a > max)
				max = a;
		}
		cout << "Case " << ++cnt << ": " << max << "\n";		
	}	
	
	return 0;
}
