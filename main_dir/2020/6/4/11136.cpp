#include <iostream>
#include <set>
using namespace std;

int main()
{
	int n;
	while (cin >> n, n)
	{
		multiset<int> Bills;
		long sum = 0;
		int nr_bills, tmp;
		for (int i = 0; i < n; ++i)
		{
			cin >> nr_bills;
			
			for (int j = 0; j < nr_bills; ++j)
			{
				cin >> tmp;
				Bills.insert(tmp);
			}
			
			sum += *(--Bills.end()) - *(Bills.begin());
			if (!Bills.empty())
				Bills.erase(Bills.begin());
			if (!Bills.empty())
				Bills.erase(--Bills.end());
		}
		cout << sum << endl;
	}
}
