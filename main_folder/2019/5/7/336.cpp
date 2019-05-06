#include <iostream>
#include <tuple>
#include <vector>
#include <set>
#include <queue>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void addEdge(int a, int b, vvi& G)
{
	int ind_a = -1, ind_b = -1;
	for (int i = 0; i < G.size(); ++i)
		if (G[i][0] == a)
			ind_a = i;
		else if (G[i][0] == b)
			ind_b = i;
			
	if (ind_a == -1)
		ind_a = G.size(), G.emplace_back(1, a);
	if (ind_b == -1)
		ind_b = G.size(), G.emplace_back(1, b);
		
	G[ind_a].push_back(b);
	G[ind_b].push_back(a);
}

int main()
{
	int e, cnt = 0, a, b;
	while (cin >> e, e)
	{
		vvi G; //ith element is [vertex index, [adjacent vertices]]
		set<int> V_main;
		for (int i = 0; i < e; ++i)
		{
			cin >> a >> b;
			if (a != b) //We are not interested in single cycles
				addEdge(a, b, G);
			V_main.insert(a); V_main.insert(b);
		}

		while (cin >> a >> b, a || b)
		{
			set<int> V(V_main);
			queue<pair<int, int> > Q;
			Q.emplace(a, b);
			
			while (!Q.empty())
			{
				int top, depth, ind_top = -1;
				tie(top, depth) = Q.front();
				Q.pop();
				V.erase(top);
				
				//Find top's index:
				for (int i = 0; i < G.size(); ++i)
					if (G[i][0] == top)
						ind_top = i;
		
				if (ind_top == -1 || depth == 0)
					continue;
								
				for (int i = 1; i < G[ind_top].size(); ++i)
					if (V.find(G[ind_top][i]) != V.end())
						Q.emplace(G[ind_top][i], depth - 1);				
			}
			cout << "Case " << ++cnt << ": " << V.size() << " nodes not reachable from node "
				<< a << " with TTL = " << b << ".\n";
		}
	}
}
