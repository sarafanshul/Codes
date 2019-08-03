#include <iostream>
#include <deque>
#include <numeric>
using namespace std;

int main()
{
	int n;
	while (cin >> n, n)
	{
		deque<int> d(n, 0);
		iota(d.begin(), d.end(), 1);
		cout << "Discarded cards:";
		while (d.size() > 1)
		{
			cout << ' ' << d.front() << (d.size() <= 2 ? "" : ",");
			d.pop_front();
			d.push_back(d.front());
			d.pop_front();
		}
		cout << "\nRemaining card: " << d.front() << '\n';
	}
}
