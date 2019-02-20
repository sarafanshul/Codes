#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <functional>
using namespace std;

typedef vector<int> vi;

int main()
{
	int n, m, case_nr = 1;
	while (cin >> n)
	{
		vector<vi> A(n, vi(n));
		vi InDeg(n), Res;
		priority_queue<int, vi, greater<int> > PQ;
		map<string, int> M; 
		vector<string> N(n); //Names i.e. reverse map
		string s, t;
		for (int i = 0; i < n; ++i)
			cin >> s, M[s] = i, N[i] = s;
		
		cin >> m;
		for (int i = 0; i < m; ++i)
		{
			cin >> s >> t;
			if (!A[M[s]][M[t]]) //Multiple edges
				InDeg[M[t]]++;
				
			A[M[s]][M[t]] = 1;
		}
		
		for (int i = 0; i < n; ++i)
			if (!InDeg[i])
				PQ.push(i);
				
		while (!PQ.empty())
		{
			int u = PQ.top(); PQ.pop();
			Res.push_back(u);
			for (int i = 0; i < n; ++i)
				if (A[u][i])
				{
					A[u][i] = 0;
					InDeg[i]--;
					if (!InDeg[i])
						PQ.push(i);
				}
		}
		
		cout << "Case #" << case_nr++ << ": Dilbert should drink beverages in this order:";
		for (auto it = Res.begin(); it != Res.end(); ++it)
			cout << ' ' << N[*it];
		cout << ".\n\n";
	}
}
