#ifndef CUST_DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
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
	ll n ,m;
	cin >> n >> m;
	vector<string > a(n);
	ll ans = 0;
	for(ll i = 0 ; i < n ; i++) 
		cin >> a[i];

	ll dp[n][m] , mx_h[n][m] ;
	memset(dp ,0 ,sizeof(dp));
	memset(mx_h ,0 ,sizeof(dp));

	auto can = [&](ll x ,ll y) -> bool {
		if(x < n && y >= 0 && y < m){
			return a[x][y] == '*';
		}
		return 0;
	};

	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < m ; j++){
			if(a[i][j] == '*'){
				dp[i][j] = 1;
				for(ll k = 0 ; k < m ;k++){
					if(can(i ,j + k) && can(i ,j - k))mx_h[i][j] = k;
					else break;
				}
				mx_h[i][j]++;
				if(i)dp[i][j] = min(dp[i-1][j] + 1 ,mx_h[i][j]) ;
			}
			ans += dp[i][j];
		}
	}

	cout << ans <<'\n';
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	int t = 1;	
	cin >> t;
	for(int i = 1 ; i <= t ;i++){ check(); }
	return 0;
}
