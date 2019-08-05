#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int main()
{
	int k;
	while (cin >> k)
	{
		vector<pair<int, int> > A;
		for (int y = k + 1; y <= 2 * k; ++y)
		{
			double x = k * y / (y - k);
			if (x * y == k * (x + y))
				A.emplace_back(int(x), y);	
		}
		
		cout << A.size() << "\n";
		for (auto el : A)
			cout << "1/" << k << " = 1/" << el.first << " + 1/" << el.second << "\n";
	}
}
