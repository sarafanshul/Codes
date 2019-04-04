#include <iostream>
#include <set>
#include <iterator>
using namespace std;

int main()
{
	int T, n, x;
	cin >> T;
	while (T--)
	{
		multiset<int> M;
		int sum = 0;
		cin >> n;
		
		for (int i = 0; i < n; ++i)
		{
			cin >> x;
			auto it = M.insert(x);
			sum += distance(M.begin(), it);
		}
		
		cout << sum << "\n";
	}	
}
