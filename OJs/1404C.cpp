// https://codeforces.com/contest/1405/problem/C

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
	int n ,k;
	string s;
	cin >> n >> k >> s;
	int temp ,zer = 0 ,one = 0;
	bool f = 1;
	for(int i = 0 ;i < k; i++){
		temp = -1;
		// check if (ti == t(i+k))
		for(int j = i ;j < n ;j+=k){
			if (s[j] != '?'){
				if(temp != -1 && (s[j] - '0' != temp)){f = 0;break;} // break condition
				temp = s[j] - '0';
			}
		}
		if(temp != -1){ (temp == 0 ? zer : one)++; }
	}
	if(max(zer ,one) > k/2){ f = 0; }
	cout << (f ? "YES\n" : "NO\n");
	return;
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
