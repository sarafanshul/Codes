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
#define MP make_pair
using ll = long long ;
using db = long double ; // or double, if TL is tight
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
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
template< class T > using ordered_set =  tree<
	T, // Key type
	null_type, // Mapped-policy
	less<T>, // Key comparison functor
	rb_tree_tag, // Specifies which underlying data structure to use
	tree_order_statistics_node_update> ; // A policy for updating node invariants	
const long long MAXN = 2e5 +7;

void check(){
	ll n ;
	cin >> n ;
	ordered_set< array< ll , 2>> b , c ;
	vector<array< ll , 3 >> a(n) ;
	vector<ll> A(n) , B(n) ;

	for( ll i = 0 ; i < n ; i++ ){
		cin >> a[i][0] >> a[i][1] , a[i][2] = i ;
	}
	sort( ALL(a) , [&](const auto &x , const auto &y){
		return ( (x[0] < y[0]) || ( x[0] == y[0] && x[1] > y[1] ) ) ;
	} ) ;

	for(ll i = 0 , j = n - 1 ; i < n ; i++ , j--){
		A[ a[i][2] ] = i - b.order_of_key( { a[i][1] , -1 } ) ;
		B[ a[j][2] ] = c.order_of_key( { a[j][1] + 1 , -1 } ) ;
		b.insert( { a[i][1] , i } ) ;
		c.insert( { a[j][1] , i } ) ;
	}
	for(auto i : B)
		cout << i << ' ';
	cout << '\n' ;
	for(auto i: A)
		cout << i <<' '; 
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	int t_c = 1;	
	// cin >> t;
	for(int i = 1 ; i <= t_c ;i++){ print("Case : " , i) ; check(); }
	return 0;
}
