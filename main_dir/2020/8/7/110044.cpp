#include <iostream>
#include <cmath>
#include <cstdint>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int64_t n, m;
		cin >> n >> m;
		int64_t res = ceil((n - 2) / 3.0) * ceil((m - 2) / 3.0);
		cout << (n > 2 && m > 2 ? res : 0) << endl;
	}
		
	return 0;
}
