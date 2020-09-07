// pragma for fast runtime optimization
// // #pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

// header(s)
#include <bits/stdc++.h>

// custom aliases
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define MP make_pair
// // for overflow
// #define int long long
// #define MAX LONG_LONG_MAX
// #define MIN LONG_LONG_MIN

// namespaces
using namespace std;

// global declerations
const size_t MAXN = 2*(1e5 +7);

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
unordered_map< long long, long long, custom_hash> _keys ,_orig;

long long idx = 1 , n ,k;

void _compress(){
	sort(ALL(v));
	for(size_t i = 0 ; i < n ; i++){
		if( _keys.find(v[i]) == _keys.end() ){
			_keys[v[i]] = idx; // for storing compression
			_orig[idx] = v[i]; // for searching back
			idx++;
		}
	}
	for(size_t i = 0; i < a.szie(); i++){
		a[i] = _keys[a[i]]; // for appliting compression
	}
}



void check(){
	cin >> n >> k;
	vector<long long> x(n) ,y(n);
	for(int i= 0; i <n ;i++)cin >> x[i];
	// _compress();
	for(int i = 0; i < n; i++) cin >> y[i]; // y-axis is not needed;

	sort(ALL(x));
	vector<ll> li(n+1) ,ri(n+1);
	li[0] = 0; ri[n-1] = 0;
	int j = 0;
	
	for(int i = 0 ;i < n ;i++){
		while(x[i] - x[j] > k) ++j;
		li[i] = i - j + 1;
	}
	j = n-1;
	for(int i = n - 1 ; i>= 0; i--){
		while(x[j] - x[i] > k) j--;
		ri[i] = j - i + 1;
	}
	// prefix max array of li
	for(int i = 1 ;i < n ;i++) li[i] = max(l[i] ,li[i-1]);
	// suffix max array of ri
	for(int i = n - 2 ; i >= 0; i--) ri[i] = max(ri[i] ,ri[i+1]);
	
	ll ans = 0;
	for (int i = 0; i < n - 1; ++i) ans = max(ans, r[i + 1] + l[i]);
	cout << ans <<"\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;

	while(t--){
		check();
	}

	return 0;
}
