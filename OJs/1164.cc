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
	pair<ll ,ll> , // Key type
	null_type, // Mapped-policy
	less<pair<ll ,ll>>, // Key comparison functor
	rb_tree_tag, // Specifies which underlying data structure to use
	tree_order_statistics_node_update> // A policy for updating node invariants
ordered_set;

const long long MAXN = 1e5 +7;

void check(){
	ll n;
	cin >> n;
	array<ll ,3> a[n] ;
	for(ll i = 0 ; i < n ; i++){
		cin >> a[i][0] >> a[i][1] ; a[i][2] = i;
	}

	sort(a , a + n) ; // sort based on arrival day

	priority_queue<pair<ll ,ll>> pq ;

	ll ans[n] , cnt = 0;
	for(auto x : a){
		if( pq.empty() || x[0] <= -pq.top().F )
			ans[x[2]] = ++cnt ; // allocate a new room
		else{
			ans[x[2]] = -pq.top().S ; // can use that room for the next guest
			pq.pop() ;
		}
		pq.push( {-x[1] , -ans[x[2]]} ) ;
	}
	cout << cnt << '\n' ;
	for(auto x : ans) 
		cout << x <<' ';
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
