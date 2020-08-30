// Binary Index Tree
// https://www.youtube.com/watch?v=kPaJfAUwViY
//
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
// #define INT_MAX LONG_LONG_MAX
// #define INT_MIN LONG_LONG_MIN
 
// namespaces
using namespace std;
 
// global declerations
const size_t MAXN = 1e5 +7;
 
struct BIT{
	int size;
	vector<int> table;
 
	BIT(int n){
		size = 1;
		while(size < n) size *= 2;
		table.assign(2*size ,0);
	}
 
	void update(int i ,int delta){
		while(i < size){
			table[i] += delta;
			i += i & -i; // add lowest bit; 
		}
	}
 
	int sum(int i){
			int _sm = 0;
		while(i > 0){
			_sm += table[i];
			i -= i & -i;
		}
		return _sm;
	}
 
	inline int _sum(int l ,int r){
		return sum(r) - sum(l);
	}
 
};
 
int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	cin.exceptions(cin.failbit);
	
	int n ;
	cin >> n;
	vector<int> a(n);
	for(size_t i = 0; i < n ;i++) cin >> a[i];
 
	BIT bt(n+1);
	int res = 0;
	vector<int> out;
	out.reserve(n+1);
	for(int i : a){
		res = bt._sum(i ,n);
		bt.update(i ,1);
		
		cout << res << " ";
	}
// 	cout << res;
	return 0;
}
