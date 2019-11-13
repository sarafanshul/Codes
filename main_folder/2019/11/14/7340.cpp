#include <iostream>
using namespace std;

typedef long long ll;

ll f(ll n)
{
    ll le = 1, cnt, ri, sum = 0;
    while (le <= n)
    {
        cnt = n / le;
        ri = n / cnt;
        sum += cnt * (ri - le + 1) * (le + ri) / 2;
        le = ri + 1;
    }

    return sum - 1;
}

int main()
{
    int n;
    while (cin >> n, n)
        cout << f(n) << '\n';
}    
