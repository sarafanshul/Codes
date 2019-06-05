#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

typedef vector<string> vs;
vs G;

int dx[] = {1, 0,  0, -1};
int dy[] = {0, 1, -1,  0};
char wall;

void dfs(int a, int b, char c)
{
	if (a >= 0 && b >= 0 && a < G.size() && b < G[a].size() && G[a][b] == ' ')
	{
		G[a][b] = c;
		for (int i = 0; i < 4; ++i)
			dfs(a + dx[i], b + dy[i], c);
	}
}

int main()
{
	string s = "?";
	while (cin.peek() != EOF)		
	{	
		G.clear(); 	
		while (getline(cin, s), s[0] != '_')
			G.push_back(s);
			
		//Find wall character
		int it = 0, a = -1;
		while (a == -1)
			a = G[it].find_first_not_of(' '), ++it;
		wall = G[it - 1][a];
		
		//DFS
		for (int i = 0; i < G.size(); ++i)
			for (int j = 0; j < G[i].size(); ++j)
				if (G[i][j] != ' ' && G[i][j] != wall)
				{
					char fill = G[i][j];
					G[i][j] = ' ';
					dfs(i, j, fill);					
				}

		for (string& g : G)
			cout << g << '\n';
		cout << s << '\n';
	}
}
