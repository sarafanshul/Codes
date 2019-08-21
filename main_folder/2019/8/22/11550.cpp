#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> vi;

int main()
{
	int T, m, n;
	cin >> T;
	while (T--)
	{
		bool flag = true;
		cin >> n >> m;
		vector<vi> I(n, vi(m)), A(n, vi(n));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cin >> I[i][j];
		
		for (int i = 0; i < m; ++i)
		{
			vector<int> V;
			for (int j = 0; j < n; ++j)
				if (I[j][i])
					V.push_back(j);

			if (V.size() == 2)
			{
				A[V[0]][V[1]]++;
				A[V[1]][V[0]]++;
				if (A[V[0]][V[1]] > 1)
				{
					flag = false;
					break;
				}
			}
			else
			{
				flag = false;
				break;
			}
		}
		cout << (flag ? "Yes\n" : "No\n");
	}
}
