#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <queue>
#include <string>
#include <sstream> 
#include <tuple>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
#define INF 1000000000

void dijkstra(vvii& AdjList, vi& dist, int s)
{
    priority_queue<ii, vector<ii>, greater<ii> > pq; pq.emplace(0,s);

    while (!pq.empty())
    {
        int d, u;
        tie(d, u) = pq.top(); pq.pop();

        if (d > dist[u])
            continue;
        
        for (ii v : AdjList[u])
        {
            if (dist[u] + v.second < dist[v.first])
            {
                dist[v.first] = dist[u] + v.second;
                pq.emplace(dist[v.first], v.first);
            }
        }
    }
}

int main()
{
    int T, F, V, s, u, v, w;
    cin >> T;
    while (T--)
    {
        vvii AdjList;
        cin >> F >> V;
        
        vi fire(F);
        for (int i = 0; i < F; ++i)
            cin >> fire[i], fire[i]--;

        cin.ignore();
        AdjList.assign(V, vii());
        string str;
        while (cin.peek() != '\n' && !cin.eof())
        {
            getline(cin, str);
            istringstream iss(str);
            iss >> u >> v >> w; --u; --v;
            AdjList[u].emplace_back(v, w);
            AdjList[v].emplace_back(u, w);   
        }

        vi closestFS(V, INF);
        for (int i : fire)
        {
            vi dist(V, INF); dist[i] = 0;
            dijkstra(AdjList, dist, i);
            for (int i = 0; i < V; ++i)
                if (dist[i] < closestFS[i])
                    closestFS[i] = dist[i];
        }            

        int best = INF, ind = -1;
        for (int i = 0; i < V; ++i)
        {
            vi dist(V, INF);
            dist[i] = 0;
            dijkstra(AdjList, dist, i);

            int far = -1;
            for (int i = 0; i < V; ++i)
                far = max(far, min(dist[i], closestFS[i]));

            if (far < best)
            {
                best = far;
                ind = i;
            }            
        }

        cout << ind + 1 << "\n";
        if (T)
            cout << "\n";
    }
}
