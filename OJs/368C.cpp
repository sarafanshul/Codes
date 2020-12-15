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
ll a[MAXN][100];

void check(){
	string s;
	cin >> s;
	memset(a ,0LL ,sizeof(a));
	for(ll i = 1 ;i <= s.size() ;i++){
		a[i][s[i-1]-'a']++;
	}
	for(ll i = 1 ;i < MAXN ;i++){
		for(ll j = 0 ;j < 100 ;j++){
			a[i][j] += a[i-1][j];
		}
	}
	ll m ,l ,r;
	cin >> m;
	while(m--){
		cin >> l >> r;
		vector<ll> cnt(3 ,0);		
		cnt['x' - 'x'] = a[r]['x'-'a'] - a[l-1]['x'-'a'];
		cnt['y' - 'x'] = a[r]['y'-'a'] - a[l-1]['y'-'a'];
		cnt['z' - 'x'] = a[r]['z'-'a'] - a[l-1]['z'-'a'];
		ll df = 0;
		sort(ALL(cnt) ,greater<ll>());
// 		cout << cnt<<"\n";
		if(cnt[0] >= cnt[2]+2 && r-l >= 2) cout << "NO\n";
		else cout <<"YES\n";
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
