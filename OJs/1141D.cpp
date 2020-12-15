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
	vector<ll> l[100]  ,r[100] , r_all ,l_all;
	string li ,ri ;
	cin >> li >> ri;
	for(ll i = 0 ; i < n ; i++){
		if( li[i] == '?')
			l_all.PB(i);
		else 
			l[ li[i] - 'a' ].PB(i);

		if( ri[i] == '?')
			r_all.PB(i);
		else 
			r[ ri[i] - 'a' ].PB(i);
	}

	vector<pair<ll ,ll>> ans;

	for(ll i = 0 ; i < n ; i++){

		if(li[i] != '?' && l[ li[i] - 'a' ].size() > 0){
			if(r[ li[i] - 'a' ].size() > 0 || r_all.size() > 0){

				ll x = l[ li[i] - 'a' ].back();
				l[ li[i] - 'a' ].pop_back();

				if( r[ li[i] - 'a' ].size() > 0 ){
					ans.PB( MP(x , r[ li[i] - 'a' ].back()) );
					r[ li[i] - 'a' ].pop_back();
				}else{
					ans.PB( MP(x ,r_all.back()) );
					r_all.pop_back();
				}
			}
		}
		if(ri[i] != '?' && r[ ri[i] - 'a' ].size() > 0 ){

			if(l[ ri[i] - 'a' ].size() > 0 || l_all.size() > 0 ){
				ll x = r[ ri[i] - 'a' ].back();
				r[ ri[i] - 'a' ].pop_back();

				if(l[ ri[i] - 'a' ].size() > 0){
					ans.PB(MP( l[ ri[i] - 'a' ].back() ,x ) );
					l[ ri[i] - 'a' ].pop_back();
				}else{
					ans.PB( MP( l_all.back() ,x ));
					l_all.pop_back();
				}
			}
		}
	}
	for(ll i = 0 ; i < l_all.size() ; i++){
		for(ll j = 0 ; j < 100 ; j++){

			while(r[j].size() > 0 && l_all.size() > 0){
				ans.PB(MP( l_all.back() ,r[j].back() ));
				l_all.pop_back();
				r[j].pop_back();
			}
		}
	}

	for(ll i = 0 ; i < r_all.size() ; i++){
		for(ll j = 0 ; j < 100 ; j++){

			while(l[j].size() > 0 && r_all.size() > 0){
				ans.PB(MP( l[j].back() ,r_all.back() ));
				r_all.pop_back();
				l[j].pop_back();
			}
		}
	}

	if(l_all.size() > 0 && r_all.size() > 0){

		while(l_all.size() > 0 && r_all.size() > 0){
			ans.PB( MP(l_all.back() ,r_all.back()));
			l_all.pop_back();
			r_all.pop_back();
		}
	}

	cout << ans.size() <<'\n';
	for(auto &pi : ans){
		cout << pi.F + 1 <<' ' << pi.S + 1 <<'\n';
	}

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
