#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int wo = 0;

vi f(vi A)
{
	vi res;
	for (int i = 0; i < A.size() / 2; ++i)
	{
		if (A[2 * i] + A[2 * i + 1] == 1)
			++wo;
		res.push_back(A[2 * i] && A[2 * i + 1]);
	}
	return res;
}

int main()
{
	int T, n, m, tmp;
	cin >> T;
	while (T--)
	{
		wo = 0;
		cin >> n >> m;
		vi A(1 << n);
		for (int i = 0; i < m; ++i)
		{
			cin >> tmp;
			A[tmp - 1] = 1;
		}
		
		while(A.size() > 1)
			A = f(A);
		
		cout << wo << '\n';
	}	
}
