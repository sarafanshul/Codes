#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int set = 1;
	while (cin.peek() != EOF)
	{
		unsigned A[20][20];
		memset(A, -1, 400 * sizeof(unsigned));
		int n, k, l;
		
		for (int i = 1; i < 20; ++i)
		{
			cin >> n;
			for (int j = 0; j < n; ++j)
			{
				cin >> k;
				A[i - 1][k - 1] = 1;
				A[k - 1][i - 1] = 1;
			}
		}
				
		for (int k = 0; k < 20; ++k)
			for (int i = 0; i < 20; ++i)
				for (int j = 0; j < 20; ++j)
					A[j][i] = A[i][j] = ::min(A[i][j], A[i][k] + A[k][j]);
					
					
		cin >> n;
		cout << "Test Set #" << set++ << "\n";
		for (int i = 0; i < n; ++i)
		{
			cin >> k >> l;
			cout << (k < 10 ? " " : "") << k << " to " << (l < 10 ? " " : "") << l << ": " << A[k - 1][l - 1] << "\n";
		}
		
		cin.ignore();
		cout << "\n";
	}	
}
