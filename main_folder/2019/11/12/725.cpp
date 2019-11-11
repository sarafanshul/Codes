#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

bool diff(string a)
{
	int A[10] = {};
	for (char c : a)
		if (isdigit(c))
			A[c - '0']++;
			
	return all_of(A, A + 10, [&](int x){return x < 2;});
}

bool req(string a, string b)
{
	if (b.size() != 5)
		return false;
	
	int A[10] = {};
	for (char c : a + b)
		if (isdigit(c))
			A[c - '0']++;
	
	return all_of(A, A + 10, [&](int x){return x == 1;});
}

int main()
{
	int n, cnt = 0;
	while (cin >> n, n)
	{
		if (cnt++ > 0)
			cout << "\n";
			
		bool flag = false;
		for (int i = 1234; i <= 49382; ++i)
		{
			string a = to_string(i), b = to_string(n * i);
			a = (a.size() == 4 ? "0" + a : a);
			b = (b.size() == 4 ? "0" + b : b);
			if (n * i >= 2468 && diff(a) && req(a, b))
				cout << b << " / " << a << " = " << n << "\n", flag = true;
				
		}
		
		if (!flag)
			cout << "There are no solutions for " << n << ".\n";
	}
}
