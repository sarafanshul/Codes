#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int N;
	cin >> N;
	while (N--)
	{
		int T, d;
		cin >> T >> d;
		while (T--)
		{
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			if (a == c && b == d)
				cout << 0 << "\n";
			else if (abs(c - a) == abs(d - b))
				cout << 1 << "\n";
			else if ( (a + b) % 2 != (c + d) % 2)
				cout << "no move\n";
			else
				cout << 2 << "\n";
		}
	}	
}
