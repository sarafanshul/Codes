#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
	int n;
	while (cin >> n, n > 0)
	{
		cin.ignore();
		int A[n], max = 0;
		
		for (int i = 0; i < n; ++i)
		{
			string str;
			getline(cin, str);
			A[i] = count(str.begin(), str.end(), 'X');
			if (A[i] > max)
				max = A[i];
		}		
		int res = n * max - accumulate(A, A + n, 0);
		cout << res << '\n';
	}
}
