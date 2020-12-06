
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

struct segtree {
	int size;
	vector<long long> _xor;

	void init(int n){
		size = 1;
		while (size < n) size *= 2;
		_xor.assign(2*size , 0LL);
	}

	void build(vector<int> &a ,int x ,int lx ,int rx){
		if(rx - lx == 1){
			if (lx < (int)a.size()){
				_xor[x] = a[lx];
			}
			return;
		}
		int m = (lx +rx) / 2;
		build(a ,2*x + 1 ,lx ,m);
		build(a ,2*x + 2 ,m ,rx);
		_xor[x] = _xor[2*x + 1] ^ _xor[2*x + 2];
	}

	void build(vector<int> &a){
		build(a ,0 ,0 ,size);
	}

	void set(int i ,int v ,int x ,int lx ,int rx){
		if (rx - lx == 1){
			_xor[x] = v;
			return;
		}
		int m = (lx + rx) /2;
		if (i < m){
			set (i ,v ,2*x + 1 ,lx ,m);
		} else {
			set(i ,v ,2*x + 2 ,m ,rx);
		}
		_xor[x] = _xor[2*x + 1] ^ _xor[2*x + 2];
	}

	void set(int i  ,int v){
		set(i ,v ,0  ,0 ,size);
	}

	long long xor_upd(int l ,int r , int x ,int lx ,int rx){
		// 3 cases
		if (lx >= r || l >= rx) return 0;
		if (lx >= l && rx <= r) return  _xor[x];
		int m = (lx + rx)/2;
		long long s1 = xor_upd(l ,r ,2*x + 1 ,lx ,m);
		long long s2 = xor_upd(l ,r ,2*x + 2 ,m ,rx);
		return s1 ^ s2;  
	}

	long long xor_upd(int l ,int r){
		return xor_upd(l ,r ,0 ,0 ,size);
	}
};

int main(){
	ios::sync_with_stdio(false);

	int n , m ;
	cin  >> n >> m;

	segtree st;
	st.init(n);
	vector<int> a(n);

	for (int  i = 0; i < n; i++) cin >> a[i];

	st.build(a);

	while (m-- ){
		int l ,r;
		cin >> l >> r;
		cout << st.xor_upd(l-1 ,r) << "\n";
	}

	return 0;
}
