// coordinate compression + BIT // CSES 1144
#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define double long double
#define MP make_pair
using namespace __gnu_pbds;
using namespace std;
#ifdef CUST_DEBUG 
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.x<<','<<p.y<<'>';return s;}
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.F<<','<<p.S<<'>';return s;}
template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>
ostream& operator<<(ostream&s,const T&v){s<<'[';for(auto&x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}
void __prnt(){cerr<<endl;} template<class T, class...Ts>void __prnt(T&&a,Ts&&...etc){cerr<<a<<' ';__prnt(etc...);}
#define print(...) __prnt(__VA_ARGS__)
#else
#define print(...)
#endif
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p){return cout<<"("<<p.F<<", "<<p.S<<")";}
template<typename A> ostream& operator<<(ostream &cout,vector<A> const &v){cout<<"[";for(int i=0;i<v.size();i++){if(i)cout<<", ";cout<<v[i];}return cout<<"]";}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p){cin>>p.F;return cin>>p.S;}


struct custom_hash_ll {
    static uint64_t splitmix64(uint64_t x) {
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

const long long MAXN = 1e6 +7;

struct query{
	char t;
	ll l ,r;
}qr[MAXN];

ll inp[MAXN] ,n ,q;
vector<ll> a;
ll BIT[MAXN];

void update(ll pos ,ll val){
	while(pos < MAXN){
		BIT[pos] += val;
		pos += (pos & -pos);
	}
}

ll query(ll pos){
	ll ans = 0;
	while(pos){
		ans += BIT[pos];
		pos -= (pos & -pos);
	}
	return ans;
}

gp_hash_table<long long, long long ,custom_hash_ll> M;
vector<long long> b;
void compress(){
	b = a;
	sort(b.begin(), b.end());
	for(int i = 0 ;i < b.size() ;i++){ M[b[i]] = i; }
	for(int i = 0 ; i < b.size() ;i++){ a[i] = M[a[i]]; }
}

void check(){
	cin >> n >> q;
	a.PB(0);
	for(ll i = 1 ;i <= n ; i++){
		cin >> inp[i];
		a.PB(inp[i]);
	}
	for(ll i = 1 ; i <= q ;i++){
		cin >> qr[i].t >> qr[i].l >> qr[i].r;
		a.PB(qr[i].l);
		a.PB(qr[i].r);
	}
	compress();
	for(ll i = 1 ;i <= n ;i++){ update(a[i] ,1); }
	
	for(ll i = 1 ;i <= q ;i++){
		ll li = qr[i].l ,ri = qr[i].r;
		if(qr[i].t == '!'){
			ll pos = a[li];
			update(pos ,-1);
			pos = M[ri];
			update(pos ,1);
			a[li] = pos;
		}else { cout << query(M[ri]) - query(M[li] - 1)<<"\n"; }
	}
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	// cin.exceptions(cin.Failbit);
	int t = 1;	
	// cin >> t;
	for(int i = 1 ; i <= t ;i++){
		// cout << "Case "<< i << ":\n";
		check();
	}
	return 0;
}
