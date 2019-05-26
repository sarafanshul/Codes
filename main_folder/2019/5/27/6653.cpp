#include <iostream>
using namespace std;

typedef long long ll;
const ll mod = 10000000000007;

int main()
{
    int t, l, m, n;
    cin >> t;
    for (int T = 1; T <= t; ++T)
    {
        cin >> l >> m >> n;
        l *= l;
        ll sum = l - n + 1;
        for (ll i = 1; i <= n - m; ++i)
            sum = ((l - n + i + 1) * (1 + sum)) % mod;

        for (ll i = l; i > l - m + 1; --i)
            sum = (sum * i) % mod;
            
        cout << "Case " << T << ": " << sum << '\n';
    }
}
