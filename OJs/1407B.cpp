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
	int n ;
	cin >> n;
	int a[n+1];
	int r_gcd = 0;
	bool vis[n] ={0};
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
	}
	for(int i =0 ; i < n ; i++){
		int tar = -1;
		for(int j = 0; j < n ;j++){
			if(!vis[j]){
				if(tar == -1 || (__gcd(r_gcd ,a[j]) > __gcd(r_gcd ,a[tar]) )) tar = j;
			}
		}
		r_gcd = __gcd(r_gcd ,a[tar]);

		cout << a[tar] << " ";
		vis[tar] = 1;
	}
	cout <<"\n";
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