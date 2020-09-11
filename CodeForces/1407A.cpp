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
const size_t MAXN = 1e5 +7;


void check(){
	int n;
    cin >> n;
    vector<int>a(n), ans;
    int cnt0 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (!a[i]) cnt0++;
    }
    int cnt1 = n - cnt0;
    if (cnt0 >= n / 2) {
        cout << cnt0 << '\n';
        for (int i = 0; i < cnt0; i++) cout << 0 << ' ';
    } else {
        cout << cnt1 - cnt1 % 2 << '\n';
        for (int i = 0; i < cnt1 - cnt1 % 2; i++) {
            cout << 1 << ' ';
        }
    }
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	cin.exceptions(cin.failbit);

	int t;
	cin >> t;

	while(t--){
		check();cout << "\n";
	}

	return 0;
}
