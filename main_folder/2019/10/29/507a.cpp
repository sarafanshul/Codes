#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;

int main()
{
	int T, b;
	cin >> T;
	for (int no = 1; no <= T; ++no)
	{
		cin >> b; --b;
		vi A(b);
		for (int i = 0; i < b; ++i)
			cin >> A[i];
		
		int max_so_far = 0, max_until_here = 0, curr = 0, start = -1, end = -1;
		for (int i = 0; i < b; ++i)
		{			
			max_until_here += A[i];
			if (max_until_here < 0)
				max_until_here = 0, curr = i + 1;
			else if (max_so_far < max_until_here || max_so_far == max_until_here && i + 1 - curr > end - start)
				max_so_far = max_until_here, start = curr, end = i + 1;
		}
		
		if (end >= 0)
			cout << "The nicest part of route " << no << " is between stops " << start + 1 << " and " << end + 1 << "\n";
		else
			cout << "Route " << no << " has no nice parts\n";
	}
}
