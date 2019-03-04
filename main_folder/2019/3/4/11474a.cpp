#include <iostream>
#include <numeric>
#include <vector>
#include <tuple>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

bool near(ii& p, ii& q, int d)
{
    int x, y, w, z;
    tie(x, y) = p;
    tie(w, z) = q;
    return (x - w) * (x - w) + (y - z) * (y - z) <= d * d;
}

bool close(vii& a, vii& b, int d)
{
    for (ii& p : a)
        for (ii& q : b)
            if (near(p, q, d))
                return true;

    return false;
}

struct UF
{
    vi r, p;
    UF(int n) : r(n, 0), p(n, 0)
    {
        iota(p.begin(), p.end(), 0);
    }
	
    int f(int x)
    {
        return (p[x] == x ? x : p[x] = f(p[x]));
    }
	
    void u(int i, int j)
    {
        int x = f(i), y = f(j);
        if (x == y)
            return;

        if (r[x] >= r[y])
        {
            p[y] = x;
            if (r[x] == r[y])
                r[x]++;
        }
        else
            p[x] = y;
    }

    bool s(int i, int j)
    {
        return f(i) == f(j);
    }
};

int main()
{
    int t, n, m, d, k, x, y, b;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k >> d;
        UF uf(10 * n + m);
        vii D;
        for (int i = 0; i < m; ++i)
        {
            cin >> x >> y;
            D.emplace_back(x, y);
        }
        
        vvii G(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> b;
            for (int j = 0; j < b; ++j)
            {
                cin >> x >> y;
                G[i].emplace_back(x, y);
                uf.u(10 * i, 10 * i + j);
            }
        }
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (close(G[i], G[j], k))
                    uf.u(10 * i, 10 * j);

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                for (ii& el : G[j])
                    if (near(D[i], el, d))
                        uf.u(10 * n + i, 10 * j);

        bool flag = false;
        for (int i = 0; i < m && !flag; ++i)
            if (uf.s(10 * n + i, 0))
                flag = true;

        if (flag)
            cout << "Tree can be saved :)\n";
        else
            cout << "Tree can't be saved :(\n";
    }
    
}
