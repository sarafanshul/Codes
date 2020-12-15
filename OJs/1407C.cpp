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

int ask(int x, int y) {
    cout << "? " << x + 1 << ' ' << y + 1 << endl;
    int z;
    cin >> z;
    if(z == -1) exit(0);
    return z;
}
void check(){
	int n ;
	cin >> n;
	vector<int> ans(n ,-1);
	int mx = 0;
	for(int i = 1 ;i < n ;i++){
		int a = ask(mx ,i);
		int b = ask(i ,mx);
		if(a > b){ans[mx] = a;mx = i;}
		else ans[i] = b;
	}
	ans[mx] = n;
	cout << "! ";
	for (int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << endl;
	return;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	cin.exceptions(cin.failbit);

	int t = 1;
	// cin >> t;

	while(t--){
		check();
	}

	return 0;
}
