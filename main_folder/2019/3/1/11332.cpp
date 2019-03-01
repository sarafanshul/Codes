#include <iostream>
using namespace std;

int DigSum(int a)
{
	int res = 0;
	while (a > 0)
	{
		res += a % 10;
		a /= 10;
	}
	return res;
}

int main()
{
	int n;
	while (cin >> n, n != 0)
	{
		int a = n;
		while (a > 9)
			a = DigSum(a);
		cout << a << "\n";
	}
	
	
	
	return 0;
}
