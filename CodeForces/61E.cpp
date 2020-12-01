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
// #define double long double
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
	long long, 
	null_type, 
	less<long long>, 
	rb_tree_tag, 
	tree_order_statistics_node_update > ordered_set;

const long long MAXN = 1e6 +7;

ll a[MAXN] ,n;

void check(){
	cin >> n;
	for(ll i = 0 ; i < n ; i++){
		cin >> a[i];
	}
	ordered_set l_set , r_set ;

	for(ll i = 1 ; i < n ; i++){
		r_set.insert(a[i]);
	}
	ll ans = 0;

	for(ll i = 0 ; i < n ; i++){
		ll left_cnt = l_set.size() - l_set.order_of_key( a[i] + 1 );
		ll right_cnt = r_set.order_of_key(a[i]);
		print(MP(a[i] ,MP( left_cnt ,right_cnt )));
		
		// larger elements in left * smaller elements in right to a[i]
		ans += left_cnt * right_cnt;

		l_set.insert( a[i] );
		r_set.erase(a[i + 1]);
	}
	cout << ans<<'\n';
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
