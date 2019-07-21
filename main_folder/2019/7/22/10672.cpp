#include <algorithm> 
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void dfs(vvi& G, vi& seen, vi& stack, int curr)
{
    if (!seen[curr])
    {
        seen[curr] = 1;
        for (int i = 1; i < G[curr].size(); ++i)
            dfs(G, seen, stack, G[curr][i]);

        stack.push_back(curr);
    }
}

    
int main()
{
    int n, v, d, tmp;
    while (cin >> n, n)
    {
        vvi G(n, vi(1, -1));
        vi has(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> v >> has[--v] >> d;
            for (int j = 0; j < d; ++j)
            {
                cin >> tmp; --tmp;
                G[v].push_back(tmp);
                G[tmp][0] = v;
            }
        }

        int root = distance(G.begin(), find_if(G.begin(), G.end(), [](vi& v){return v[0] == -1;}));
        vi seen(n), stack;
        dfs(G, seen, stack, root);

        int moves = 0;
        for (int s : stack)
        {
            if (has[s] != 1)
            {
                has[G[s][0]] += has[s] - 1;
                moves += abs(has[s] - 1);
            }
        }

        cout << moves << "\n";
    }
           
}
