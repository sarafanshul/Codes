#include <iostream>
using namespace std;

int main()
{
	int a;
	while (cin >> a, a)
	{
		int B[2] = {0, 0};
		bool flag = true;
		
		for (int i = 0; i < 32; ++i)
			if (a & (1 << i))
				B[flag = !flag] |= (1 << i);
		
		cout << B[0] << ' ' << B[1] << '\n';		
	}
}
