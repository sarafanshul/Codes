#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int tree, acorn;
vvi G;
vi V;

void dfs(int v)
{
	V[v] = 1;
	for (int u : G[v])
		if (V[u] == 0)
			dfs(u);
}

int main()
{
	int N;
	cin >> N;
	while (N--)
	{
		tree = acorn = 0;
		V.clear(); 
		G.clear();
		V.assign(26, -1);
		G.resize(26);
		string s;
		while (cin >> s, s[0] != '*')
		{
			G[s[1] - 'A'].push_back(s[3] - 'A');
			G[s[3] - 'A'].push_back(s[1] - 'A');
		}
		
		cin >> s;		
		for (int i = 0; i < (s.size() + 1) / 2; ++i)
			V[s[2 * i] - 'A'] =  0;	//-1 = not in G,  0 = not visited,  1 = visited
		
		for (int i = 0; i < V.size(); ++i)
			if (V[i] == 0)
				if (!G[i].empty())
					dfs(i),	++tree;
				else
					V[i] = 1, ++acorn;
				
		cout << "There are " << tree << " tree(s) and " << acorn << " acorn(s).\n";
	}
}
