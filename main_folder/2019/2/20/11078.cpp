#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, T;
	cin >> T;
	while (T--)
	{
		cin >> n;
		int A[100000] = {};
		for (int i = 0; i < n; ++i)
			cin >> A[i];
		
		int m = -300001, ref = 0;
		if (!is_sorted(A, A + n))
		{
			for (int i = 0; i < n; ++i)
			{
				if (A[i] > A[ref])
					ref = i;
				else
					m = max(m, A[ref] - A[i]);
			}
		}
		else
			for (int i = 1; i < n; ++i)
				m = max(m, A[i - 1] - A[i]);
				
		cout << m << "\n";
	}
	
}
