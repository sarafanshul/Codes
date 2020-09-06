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
	vector<int> inp(n);
	for(int i = 0; i < n; i++) cin >> inp[i];
	int l = 0 ,h = n-1  ;ll cnt = 0 ,zc = 0;
	int a ,b ,c;
	for(int i :inp) if(i == 0) zc++;
	while(1){
		if(zc == n) break;
        for(l = 0 ; (inp[l] >= 0 && l <n); l++);
		for(h = n-1 ;(inp[h] <= 0 && h >=0); h--);
		a = inp[l];b = inp[h];
		c = min(-a ,b);
		a += c;b -= c;
		inp[l] = a;inp[h] = b;
		if(inp[l] == 0) zc++;
		if(inp[h] == 0) zc++;
		if((l < h)) cnt += c;
	}
	cout <<cnt <<"\n";
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
