#include <iostream>
#include <string>
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

bool run_num(long a)
{
	string s = to_string(a);
	int ind = (s[0] - '0') % s.size(), A[10] = {};
	
	for (int i = 1; i < s.size(); ++i)
	{
		A[ind]++;
		ind = (ind + s[ind] - '0') % s.size();
	}
		
	A[ind]++;	
	return count_if(A, A + 10, [&](int x){return x > 1;}) < 1;
}

int main()
{
	long n, c = 0;
	while (cin >> n, n)
	{
		while (!diff_dig(n) || !run_num(n))
			++n;
		
		cout << "Case " << ++c << ": " << n << "\n";
	}
}
