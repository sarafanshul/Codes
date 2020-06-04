#include <iostream>
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
		if (n < m)
			cout << "<\n";
		else if (n == m)
			cout << "=\n";
		else
			cout << ">\n";
	}
		
	return 0;
}
