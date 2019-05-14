#include <iostream>
#include <algorithm>
using namespace std;

bool diff_dig(long a)
{
	int A[10] = {};
	while (a > 0)
	{
		A[(a % 10)]++;
		a /= 10;
	}

	return count_if(A, A + 10, [&](int x){return x > 1;}) == 0;
}

int main()
{
	long T, n;
	cin >> T;
	while (T--)
	{
		cin >> n;
		long it = 1, s = n * it;
		
		while (s < 10000000000)
		{
			if (diff_dig(s) && diff_dig(it))
				cout << s << " / " << it << " = " << n << "\n";
			++it;
			s += n;
		}
						
		cout << (T == 0 ? "" : "\n");
	}
}
