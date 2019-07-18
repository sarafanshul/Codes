#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	string s;
	int a, b, c, d;
	while (cin >> a >> b >> c >> d, a || b || c || d)
	{
		a *= 9;
		b *= 9;
		c *= 9;
		d *= 9;
		int res = 3 * 360;
		res += (a > b ?  a - b : 360 + a - b);
		res += (b > c ?  c  + 360 - b : c - b);
		res += (c > d ?  c - d : c + 360 - d);
		
		cout << res << "\n";
	}
	
	return 0;
}
