// coordinate compression
// Coordinate Compression is mainly used to map larger 
// 	values to smaller values to remove the vacant space
// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/goris-crush/submissions/ 
// https://www.quora.com/What-is-coordinate-compression-and-what-is-it-used-for
 
 
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
const size_t MAXN = 100100;
 
// FOR LONG LONG INTS (for unhackable hashing)
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
long long bit[MAXN*10];
long long idx = 1 ,n ,q ,k ,cnt = 1;
 
// Compression
void _compress(vector<long long> &v ,vector<long long> &a){ // O(Nlog(N))
	vector<long long> _a(v);
	sort(ALL(_a));
	for(size_t i = 0 ; i < _a.size() ; i++){
		if( _keys.find(_a[i]) == _keys.end() ){
			_keys[_a[i]] = idx; // for storing compression
			_orig[idx] = _a[i]; // for searching back
			idx++;
		}
	}
	for(size_t i = 1; i < a.size(); i++){
		a[i] = _keys[a[i]]; // for appliting compression
	}
	cnt = idx;
}
 
// BIT
void update(ll x ,ll val){
	while(x <= cnt){
		bit[x] += val;
		x += (x & (-x));
	}
}

long long query_bit(long long idx) {
	long long res = 0;
	while(idx) {
		res += bit[idx];
		idx -= (idx & (-idx));
	}
	return res;
}

long long query(ll x ,ll y){
	ll p = 0 ,q = 0;
	p = query_bit(--x);
	q = query_bit(y);
	return q-p;
}

void solve(){
	cin >> n >> q >> k;
	vector<ll> v ,a(MAXN);
	v.reserve(MAXN*10);
	for(int i = 1 ; i <= n; i++){
		cin >> a[i];
		v.PB(a[i]);
	}
	ll t ,x ,y ,a1 ,b ,c ,d;
	vector<vector<ll>> que(q+7);
	for(int i = 0; i < q ;i++){
		cin >> t;
		if(t == 0){
			cin >> x >> y;
			que[i] = {t ,x ,y};
			v.PB(x);v.PB(y);
		}else{
			cin >> a1 >> b >> c >> d;
			que[i] = {t ,a1 ,b ,c ,d};
			v.PB(a1);v.PB(b);v.PB(c);v.PB(d);
		}
	}

	_compress(v ,a);
    
	for(int i = 1 ;i <= n ;i++) update(a[i] ,1);
	ll m, w, z;
	for(int i = 0; i < q ;i++){
		if(que[i][0] == 0){
			update(a[ _keys[ que[i][1] ] ] ,-1);
			a[ _keys[ que[i][1] ] ] = _keys[ que[i][2] ];
			update(a[ _keys[ que[i][1] ] ] ,1);
		}
		else {
			w = _keys[que[i][1]];x = _keys[que[i][2]];y = _keys[que[i][3]];z = _keys[que[i][4]];
			if(x < y || z < w) m=0;
			else if(w <= y && z <= x) m = query(y, z);
			else if(y <= w && x <= z) m = query(w,x);
			else if(w <= y && x <= z) m = query(y, x);
			else if(y <= w && z <= x) m = query(w, z);	
			if(m >= k) cout << "Propose\n";
			else cout << "Do not propose\n";
		}
	}
 
}
 
int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	cin.exceptions(cin.failbit);
 
	solve();
 
	return 0;
}