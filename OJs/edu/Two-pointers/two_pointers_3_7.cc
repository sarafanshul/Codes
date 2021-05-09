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
#define MP make_pair
using ll = long long ;
using ld = long double ; // or double, if TL is tight
template< class T , size_t SZ> using ar = std::array<T , SZ> ; 
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
const long long MAXN = 2e5 +7;

void check(){
	ll n , c;
	cin >> n >> c ;
	string s;
	cin >> s;

	ll ans = 0 , l = 0 , aValues = 0 , bValues = 0 , currentRudness = 0 ;
	for( ll r = 0 ; r < n ; r++ ){
		if( s[r] == 'a' ) 
			aValues++;
		else if( s[r] == 'b' ){
			bValues++;
			currentRudness += aValues;
		}

		while( currentRudness>c ){
			// now move the left pointer to right as long as rudeness is more than c
			if( s[l] == 'a' ) currentRudness-=bValues , aValues-- ;
			else if( s[l] == 'b' ) bValues-- ;
			l++;
		}
		//now rudeness is less than c, check with max value
		ans=max( ans , r - l + 1 );
	}
	cout << ans ;
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	int t_c = 1;	
	// cin >> t_c;
	for(int i = 1 ; i <= t_c ;i++){ print("Case : " , i) ; check(); }
	return 0;
}
