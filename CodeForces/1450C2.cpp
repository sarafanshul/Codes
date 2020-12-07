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
	ll n;
	cin >> n;
	vector<string> s(n);
	vector<ll> x(3) , o(3);
	ll k = 0;
	for(ll i = 0 ; i < n ; i++){
		cin >> s[i];
		for(ll j = 0 ; j < n ; j++){
			if(s[i][j] == 'X'){
				x[ (i + j)%3 ] ++;
				k++;
			}
			if(s[i][j] == 'O'){
				o[ (i + j)%3 ]++;
				k++;
			}
		}
	}
	for(ll u = 0 ; u < 3 ; u++){
		for(ll v = 0 ; v < 3 ; v++){
			if( u != v && x[u] + o[v] <= k/3 ){
				for(ll i = 0 ; i < n ; i++){
					for(ll j = 0 ; j < n ; j++){
						if( (i + j)%3 == u && s[i][j] == 'X')
							s[i][j] = 'O';
						if( (i + j)%3 == v && s[i][j] == 'O')
							s[i][j] = 'X';
					}
					cout << s[i]<<'\n';
				}
				return ;
			}
		}
	}
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
