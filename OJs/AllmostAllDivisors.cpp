#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define sf(n) scanf("%d", &n)
#define sfl(n) scanf("%I64d", &n)
#define pb push_back
#define pp pair<int, int>

using namespace std;

int main()
{

    int i, j, k;
    int n, m, t, sq;
    bool f;

    sf(t);
    set<ll> s;

    while(t--)
    {
        sf(n);

        ll a[n];
        for(i = 0; i < n; i++)
            sfl(a[i]);

        sort(a, a + n);

        s.clear();
        ll mm = a[0] * a[n - 1];

        for(ll x = 2; x * x <= mm; x++)
        {
            if(mm % x == 0)
                s.insert(x), s.insert(mm / x);
        }

        f = true;
        if(s.size() == n)
        {
            for(i = 0; i < n; i++)
            {
                if(s.find(a[i]) != s.end())continue;
                f = false;
                break;
            }
        }

        else
            f = false;

        if(f)
            cout << mm <<endl;
        else
            cout<< -1 << endl;
    }

    return 0;
}