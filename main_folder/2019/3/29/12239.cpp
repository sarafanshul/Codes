#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int a, b;
	while (cin >> a >> b, a && b)
	{
		int A[b];
		bool R[a + 1];
		memset(R, false, sizeof(R));
		for (int i = 0; i < b; ++i)
			cin >> A[i];
				
		for (int i = 0; i < b; ++i)
			for (int j = i; j < b; ++j)
				R[abs(A[i] - A[j])] = true;
				
		cout << (all_of(R, R + a + 1, [](int x){return x == true;}) ? "Y\n" : "N\n");		
	}
}
