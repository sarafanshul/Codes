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
	int n ,x ,y;
	vector<int> a;
	a.reserve(1001);
	cin >> n >> x >> y;
	int d = y - x;
	bool flag= 0;
	for(int delta = 1; delta <= d ;delta++){
		int y1 = y ,n1 = n;
		for(int i = y1 ;i>=1 ,n1 > 0; i -= delta ,n1--){
		    if(i <1 ) break;
			a.PB(i);
			if(i == x)flag = 1;
		}
		if(flag){
			while(n1--){
				a.PB(y1 + delta);
				y1 += delta;
			}
			sort(ALL(a));
			for(int i = 0; i < n; i++)cout << a[i] <<" ";
			cout <<"\n";
			return;
		}else a.clear();
	}
	
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
