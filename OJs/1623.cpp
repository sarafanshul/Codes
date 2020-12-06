#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long

using namespace std;
const int MOD = 1e9+7;

inline int abs(int a ,int b) {return max(a ,b) - min(a ,b);}

ll n ,m ,t;
vector< ll> a;

void f(int i, ll s) {
  	if (i == n) {
    	ll x = s;
    	ll y = t - s;
    	if (y > x) swap(x, y);
    	m = min(x - y, m);
    	return;
  	}
  	f(i + 1, s);
  	f(i + 1, s + a[i]);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        t += a[i];
    }
    m = t;
    f(0, 0);
    cout << m << "\n";
    return 0;
}
