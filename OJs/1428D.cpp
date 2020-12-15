#pragma GCC optimize("Ofast")  // remove in mingw32 bit ;
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define double long double
#define MP make_pair
// #define int long long
// #define MAX LONG_LONG_MAX
// #define MIN LONG_LONG_MIN

using namespace std;


#ifdef CUST_DEBUG
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.F<<','<<p.S<<'>';return s;}
template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>
ostream& operator<<(ostream&s,const T&v){s<<'[';for(auto&x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}
void __prnt(){cerr<<endl;} template<class T, class...Ts>void __prnt(T&&a,Ts&&...etc){cerr<<a<<' ';__prnt(etc...);}
#define print(...) __prnt(__VA_ARGS__)
#else
#define print(...)
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p){return cout<<"("<<p.F<<", "<<p.S<<")";}
template<typename A> ostream& operator<<(ostream &cout,vector<A> const &v){cout<<"[";for(int i=0;i<v.size();i++){if(i)cout<<", ";cout<<v[i];}return cout<<"]";}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p){cin>>p.F;return cin>>p.S;}
#endif

const long long MAXN = 1e5 +7;

void check(){
	ll n;
	cin >> n;
	ll a[n];
	for(ll i = 0 ;i <  n;i++) cin>>a[i];
	vector<ll> where[4];
	vector<pair<ll ,ll>> targets;
	vector<ll> on_row(n ,-1);
	ll empty_row = 0;

	for(ll i = n-1 ;i>= 0 ;i--){
		if(a[i] == 1){
			on_row[i] = empty_row++;
			targets.PB(MP(on_row[i] ,i));
		} else if(a[i] == 2){
			if(where[1].empty()){cout << -1 ;return;}
			ll one = where[1].back();
			where[1].pop_back();
			on_row[i] = on_row[one];
			targets.PB(MP(on_row[i] ,i));
		} else if(a[i] == 3){
			bool f = 0;
			for(ll x = 3;x >= 1 ;x--){
				if(!where[x].empty()){
					ll who = where[x].back();
					where[x].pop_back();
					on_row[i] = empty_row++;
					targets.PB(MP(on_row[i] ,i));
					targets.PB(MP(on_row[i] ,who));
					f = 1;
					break;
				}
			}
			if(!f){cout <<-1 ;return;}
		}
		where[a[i]].PB(i);
	}
	cout<< targets.size() <<"\n";
	for(pair<ll ,ll> &pi: targets){
		cout << n-(pi.F) << " " << pi.S+1 <<"\n";
	}
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
