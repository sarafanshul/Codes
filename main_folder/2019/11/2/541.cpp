#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

int main()
{
	int n;
	
	while (cin >> n, n)
	{
		int A[n * n];
		vi odd_rows, odd_cols;
		for (int i = 0; i < n * n; ++i)
				cin >> A[i];
		//Check odd rows		
		for (int i = 0; i < n; ++i)			
			if ((count(A + i * n, A + (i + 1) * n, 1)) % 2)
				odd_rows.push_back(i);
		//Check odd cols
		for (int i = 0; i < n; ++i)
		{
			int sum = 0;
			for (int j = 0; j < n; ++j)
				sum += A[j*n + i];
			if (sum % 2)
				odd_cols.push_back(i);
		}
			
		if (!odd_cols.size() && !odd_rows.size())
			cout << "OK\n";
		else if (odd_cols.size() == 1 && odd_rows.size() == 1)
			cout << "Change bit (" << odd_rows[0] + 1 << "," << odd_cols[0] + 1 << ")\n";
		else
			cout << "Corrupt\n";		
	}
}
