#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float v, w;
	while (cin >> v >> w, v || w)
	{
		float n = (.5 * v / w);
		
		if (v / n > w)
		{
			if (abs(n - trunc(n)) != .5)
				cout << round(n) << "\n";
			else if (v / ceil(n) > w)
				cout << "0\n";
			else
				cout << floor(n) << "\n";
		}
		else
		{
			int i = floor(n);
			while (v / i <= w && i > 0)
				--i;
				
			cout << (i > 0 ? i : 0) << "\n";
		}
	}	
}
