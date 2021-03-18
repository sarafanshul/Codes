#ifndef CUST_DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") 
#pragma GCC optimize("unroll-loops")
#endif
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define F first
#define S second
#define ll long long
#define double long double
#define MP make_pair

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

const long long MAXN = 1e5 +7;

void check(){
	ll n , L ;
	cin >> n >>  L ;
	vector<ll> a(n) ;
	for(ll&i : a)
		cin >> i ;

	double l = 0 , r = 1e9 , m ;

	auto F = [&](double x) -> bool { // pos at xth sec 

		double pos_1 = 0 , time_1 = 0 ;
		ll spd_1 = 1 , to ;

		for(ll i = 0 ; i <= n ; i++){
			if( i == n ) to = L ;
			else to = a[i] ;

			double req = ( to - pos_1 ) / spd_1 ;
			pos_1 = min( pos_1 + min( req , x - time_1 )*spd_1 , (double)L ) ;
			time_1 = time_1 + min( req , x - time_1 ) ;
			
			if( pos_1 < to )
				break ;
			spd_1++ ;
		}

		double pos_2 = L , time_2 = 0 ;
		ll spd_2 = 1 ;

		for(ll i = n - 1 ; i >= -1 ; i--){
			if( i == -1 )
				to = 0 ;
			else 
				to = a[i] ;

			double req = ( pos_2 - to ) / spd_2 ;
			pos_2 = max( (double)0 , pos_2 - min( req , x - time_2 )*spd_2 ) ;
			time_2 = time_2 + min( req , x - time_2 ) ;

			if( pos_2 > to ) 
				break ;
			spd_2++ ;
		}
		print( "l = " ,l , " r = " , r , " mid = " , x , " pos_1 = ", pos_1 , " pos_2 = " , pos_2 ) ;
		return !(pos_1 >= pos_2) ;

	} ;


	for(ll t = 0 ; t < 100 ; t++){
		m = (l + r) / 2 ;
		if( F( m ) ){
			l = m ;
		}else {
			r = m ;
		}
	}

	cout << fixed << setprecision(10) << l << '\n' ;

}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	int t = 1;	
	cin >> t;
	for(int i = 1 ; i <= t ;i++){ print("Case : " , i) ; check(); }
	return 0;
}
