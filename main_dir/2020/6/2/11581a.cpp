#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void update(string &a)
{
	int dx[9][4] = {{1, 3, -1, -1}, {0, 2, 4, -1}, {1, 5, -1, -1}, {0, 4, 6, -1}, {1, 3, 5, 7},
					{2, 4, 8, -1}, {3, 7, -1, -1}, {4, 6, 8, -1}, {5, 7, -1, -1}};
	string copy(a);
	a = string(9, '0');
	
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 4; ++j)	
			if (dx[i][j] >= 0)
				a[i] = (a[i] + copy[dx[i][j]]) % 2 + '0';
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int cnt = -1;
		string a, tmp;
		for (int i = 0; i < 3; ++i)
		{	
			cin >> tmp;
			a += tmp;
		}
	
		while (a != "000000000")
		{
			++cnt;
			update(a);				
		}
		cout << cnt << endl;
	}	
}
