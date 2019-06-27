#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int T, r, vito;
	cin >> T;
	
	while (T--)
	{
		cin >> r;
		int A[500], res = 0;
		for (int i = 0; i < r; ++i)
			cin >> A[i];
			
		if (r % 2)
		{
			nth_element(A, A + r / 2, A + r);
			vito = A[r / 2];
		}
		else
		{
			sort(A, A + r);
			vito =  round((A[(r - 1) / 2] + A[(r + 1) / 2]) / 2);
		}
			
		for (int i = 0; i < r; ++i)
			res += abs(A[i] - vito);
			
		cout << res << "\n";
	}
}
