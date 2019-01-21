#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	string Dir[4] = {"north", "south", "east", "west"};
	int A[4][6] = {{4, 0, 2, 3, 5, 1}, {1, 5, 2, 3, 0, 4},
				   {2, 1, 5, 0, 4, 3}, {3, 1, 0, 5, 4, 2}};
	int n;
	while (cin >> n, n)
	{
		string s;
		int Die[6] = {1, 2, 3, 4, 5, 6};
		for (int i = 0; i < n; ++i)
		{
			int tmp[6];
			memcpy(tmp, Die, sizeof(Die));
			cin >> s;
			for (int j = 0; j < 4; ++j)
				if (s == Dir[j])
					for (int k = 0; k < 6; ++k)
						Die[k] = tmp[A[j][k]];
		}
		cout << Die[0] << '\n';
	}
}
