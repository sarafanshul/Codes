#ifndef CUST_DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#endif
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define F first
#define S second
#define ll long long
#define double long double
#define MP make_pair

using namespace __gnu_pbds;
using namespace std;

#ifdef CUST_DEBUG
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.F<<','<<p.S<<'>';return s;}
template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>
ostream& operator<<(ostream&s,const T&v){s<<'[';for(auto&x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}
void __prnt(){cerr<<endl;} template<class T, class...Ts>void __prnt(T&&a,Ts&&...etc){cerr<<a<<' ';__prnt(etc...);}
#define print(...) __prnt(__VA_ARGS__)
#else
#define print(...)
#endif

typedef tree<
	long long, // Key type
	null_type, // Mapped-policy
	less<long long>, // Key comparison functor
	rb_tree_tag, // Specifies which underlying data structure to use
	tree_order_statistics_node_update> // A policy for updating node invariants
ordered_set;

const long long MAXN = 1e5 +7;

void check(){
	ll n;
	cin >> n;
	vector<pair<ll ,ll>> a(n) ;
	for(ll i = 0 ; i < n ; i++){
		cin >> a[i].F ;
	}
	for(ll i = 0 ; i < n ; i++){
		cin >> a[i].S;
	}
	sort(ALL(a));

	ll now = 0 , num = 0 , ans = 0 , tmp = 0;
	priority_queue<ll> q;

	while(!q.empty() || now < n){
		num++ ;
		if(q.empty()){
			num = a[now].F ;
			while( now < n && num == a[now].F )
				tmp += a[now].S , q.push( a[now].S ) , now++;
		}else{
			while( now < n && num == a[now].F )
				tmp += a[now].S , q.push( a[now].S ) , now++;
		}
		tmp -= q.top() , q.pop();
		ans += tmp ;
	}
	cout << ans << '\n';
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	int t = 1;	
	// cin >> t;
	for(int i = 1 ; i <= t ;i++){ check(); }
	return 0;
}
