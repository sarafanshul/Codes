#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		cout << abs(((5 * (n * 63 + 7492) - 498) / 10 ))% 10 << endl;
	}
	
	return 0;
}
