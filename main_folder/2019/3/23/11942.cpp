#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	cout << "Lumberjacks:\n";
	
	while (N--)
	{
		int L[11];
		for (int i = 0; i < 10; ++i)
			cin >> L[i];
		if (is_sorted(L, L + 10) || is_sorted(L, L + 10, greater<int>()))
			cout << "Ordered\n";
		else
			cout << "Unordered\n";
		
	}
	
	return 0;
}
