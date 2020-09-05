/*
Approach 

start R -> L
	digit = n%10 ;
	we need (10-digit)%10 moves -> sub it from s;
	do this till contition satisfies(min(s) = 1[given]);
*/


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

template<typename T>
bool checkif(T n ,T s){
	T r = 0;
	while(n){r += n%10;n /= 10;}
	return (r <= s);
}

void check(){
	ll s ,n;
	cin >>n >>s;
	if(checkif(n ,s)){cout << "0\n";return;}
	
	ll pw = 1 ,digit ,ad ,ans = 0;
	for(int i = 0; i < 18 ;i++ ,pw *= 10){
		digit = (n/pw)%10;
		ad = pw*((10 - digit) %10);
		n += ad; ans += ad;
		if(checkif(n ,s)) break;
	}
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
