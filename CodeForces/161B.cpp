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
	ll n ,k ,x ,y;
	cin >> n >> k;

	vector<pair<ll ,ll> > sto ,pen;
	for(ll i = 0 ; i < n ; i++){
		cin >> x >> y;
		if(y == 1){
			sto.PB( {x ,i} );
		}else {
			pen.PB( {x ,i} );
		}
	}
	sort(ALL(sto)  );
	sort(ALL(pen)  );
	vector<vector<ll> > car(k) ;
	ll i = 0 ;
	bool has_s[k] = {0};
	vector<pair<ll ,ll>> tot(k ,MP(0 ,1e10));

	print(sto ,pen);
	ll mn = 1e10 ,mn_id = k-1;
	while(sto.size() > 0 ){
		car[ i%k ].PB( sto.back().S );
		tot[ i%k ].F += sto.back().F;
		tot[ i%k ].S = min(tot[ i%k ].S ,sto.back().F );
		sto.pop_back();
		has_s[ i%k ] = 1;

		if(i == k-1){
			while(sto.size() > 0){
				car[ i%k ].PB( sto.back().S );
				tot[ i%k ].F += sto.back().F;
				tot[ i%k ].S = min(tot[ i%k ].S ,sto.back().F );
				sto.pop_back();
				has_s[ i%k ] = 1;
				if(tot[ i%k ].S < mn){
					mn = min(mn ,tot[ i%k ].S );
					mn_id = i%k;
				}
			}
		}
		i++;
	}

	while(pen.size() > 0){
		if(i > k-1) i = mn_id;
		tot[i].F += pen.back().F;
		tot[i].S = min(tot[i].S ,pen.back().F) ;
		car[i].PB( pen.back().S );
		pen.pop_back();
		i++;
	}
	
	print(tot);
	double ans = 0;
	for(ll j = 0 ; j < k ; j++){
		if(has_s[j]){
			ans -= 1.0*tot[j].S/2.0;
		}
		ans += tot[j].F;
	}
	cout <<fixed << setprecision(1) <<ans<<'\n';

	for(ll j = 0 ; j < k ; j++){
		cout << car[j].size() <<' ';
		for(ll &id : car[j]) cout << id + 1 <<' ';
		cout << '\n';
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
