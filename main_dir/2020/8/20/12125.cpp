#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

int R[202][202], Q[202][202], s, t;
vector<vector<int>> G;
vector<int> P;
float d;

bool close(pair<int, int>& a, pair<int, int>& b)
{
    float x = a.first - b.first, y = a.second - b.second;
    return sqrt(x * x + y * y) <= d;
}

bool ap()
{
    queue<int> q;
    q.push(s);
    P.assign(s, -1);
    while (!q.empty())
    {       
        int top = q.front(); q.pop();
        if (top == t)
            return true;

        for (int i : G[top])
        {
            if (P[i] == -1 && R[top][i] > 0)
                q.push(i), P[i] = top;
        }
    }
    return false;
}

void process(int a, int b, int w)
{
    Q[a][b] = w;
    G[a].push_back(b);
    G[b].push_back(a);
}

int main()
{
    int T, n, x, y, m, w;
    cin >> T;
    while (T--)
    {
        memset(Q, 0, sizeof(Q));
        cin >> n >> d;
        G.assign(2 * n + 1, vector<int>());
        vector<pair<int, int>> C;
        s = 2 * n;

        int penguins = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> x >> y >> m >> w;
            C.emplace_back(x, y);
            penguins += m;
            if (m)
                process(s, i, m);
            process(i, i + n, w);
        }
        
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (close(C[i], C[j]))
                {
                    process(i + n, j, 1001);
                    process(j + n, i, 1001);
                }
            }
        }
        
        int flag = false;
        for (int i = 0; i < n; ++i)
        {
            t = i;
            memcpy(R, Q, sizeof(Q));
            process(i, t, 1001);
            
            int mf = 0;
            while (ap())
            {
                int aug = 1001;
                for (int it = t; it != s; it = P[it])
                    aug = min(aug, R[P[it]][it]);

                for (int it = t; it != s; it = P[it])
                    R[P[it]][it] -= aug, R[it][P[it]] += aug;

                mf += aug;
            }

            if (mf == penguins)
                cout << (flag ? " " : "") << i, flag = true;
        }
        
        if (!flag)
            cout << "-1\n";
        else
            cout << "\n";
    }
}
