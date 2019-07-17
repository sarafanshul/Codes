#include <iostream>
using namespace std;

int main()
{
	int A[10000] = {}, l, r, h, len = 0;
	
	while (cin >> l >> h >> r)
	{
		len = max(len, r);
		for (int i = l - 1; i < r - 1; ++i)
			A[i] = max(A[i], h);
	}
	
	cout << "1 " << A[0];
	for (int i = 1; i < len; ++i)
		if (A[i] != A[i - 1])
			cout << " " << i + 1 << " " << A[i];
			
	cout << endl;
}
