#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		bool A[3000];
		memset(A, false, sizeof(A));
		
		int cnt = 0;		
		int a, b;
		cin >> a;
		for (int i = 1; i < n; ++i)
		{
			cin >> b;
			int ind = abs(a-b) - 1;
			if (!A[ind] && ind < n - 1)
				A[ind] = true, cnt++;
			a = b;
		}
				
		if (cnt == n - 1)
			cout << "Jolly\n";
		else
			cout << "Not jolly\n";	
	}	
}
