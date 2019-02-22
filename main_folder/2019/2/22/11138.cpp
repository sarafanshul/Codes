#include <iostream>
#include <cstring>
using namespace std;

int bolts, nuts, fits[500][500], nut_used[500], visited[500];

bool ap(int u)
{
	if (visited[u])
		return false;
	
	visited[u] = 1;
	for (int n = 0; n < nuts; ++n)
	{
		if (fits[u][n] && (nut_used[n] == -1 || ap(nut_used[n])))
		{
			nut_used[n] = u;
			return true;
		}
	}
	return false;
}

int main()
{
	int T;
	cin >> T;
	for (int caseno = 1; caseno <= T; ++caseno)
	{
		int MCBM = 0;
		memset(nut_used, -1, sizeof(nut_used));
		cin >> bolts >> nuts;
		for (int b = 0; b < bolts; ++b)
			for (int n = 0; n < nuts; ++n)
				cin >> fits[b][n];
				
		for(int b = 0; b < bolts; ++b)
		{
			memset(visited, 0, sizeof(visited));
			MCBM += ap(b);
		}
		
		cout << "Case " << caseno << ": a maximum of " << MCBM << " nuts and bolts can be fitted together\n";
	}
}
