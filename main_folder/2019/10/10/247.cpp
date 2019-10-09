#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

typedef vector<int> vi;
vector<vi> E, rE, Res;
vector<string> N;
vi S, V;
int C;

void Kos(int u, bool pass = 0)
{
	if (pass)
		Res[C].push_back(u);
	
	V[u] = 1;
	vi neighbor = (pass ? rE[u] : E[u]);
	
	for (int i = 0; i < neighbor.size(); ++i)
		if (!V[neighbor[i]])
			Kos(neighbor[i], pass);
	
	S.push_back(u);		//Order of decreasing finishing times
}

int main()
{
	int n, m, data = 1;
	while (cin >> n >> m, n || m)
	{
		E.assign(n, vi()); rE.assign(n, vi());
		N.assign(n, "");				//ind  -> Name
		unordered_map<string, int> M;	//Name -> ind
		int cnt = 0;
		string s[2];
		
		for (int i = 0; i < m; ++i)
		{
			cin >> s[0] >> s[1];
			for (int k = 0; k < 2; ++k)
				if (M[s[k]] == 0)
					N[cnt] = s[k], M[s[k]] = ++cnt;
			
			E[M[s[0]] - 1].push_back(M[s[1]] - 1);
			rE[M[s[1]] - 1].push_back(M[s[0]] - 1);
		}
		
		S.clear();
		V.assign(n, 0);
		for (int i = 0; i < n; ++i)
			if (!V[i])
				Kos(i);
		
		cout << "Calling circles for data set " << data++ << ":\n";
		V.assign(n, 0);
		Res.assign(n, vi());
		C = 0;
		for (int i = S.size() - 1; i >= 0; --i)
			if (!V[S[i]])
				Kos(S[i], true), C++;
		
		if (m > 0)	
			for (int i = 0; i < C; ++i)
			{
				for (int j = 0; j < Res[i].size(); ++j)
					cout << (j > 0 ? ", " : "") << N[Res[i][j]];
				cout << '\n';
			}
	}
}
