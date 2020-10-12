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
	vector<ll> a(n);
	for(int i = 0 ;i <n ; i++) cin >>a[i];
	if(n == 1){cout <<"0\n";return;}

	vector<vector<ll>>ans;
	ll rev = 1;
	
	auto go = [&](const vector<ll> &d){
		ll r = 0;
		for(const ll &i : d){
			reverse(a.begin() + r ,a.begin() + r + i);
			r += i;
		}
		reverse(ALL(a));
	};

	for(int i = 1 ;i <=n ;i++){
		ll target = (i%2 ? i/2 + 1 : n+1-i/2);
		ll pos = -1;
		for(int j = 0 ; j < n ;j++){
			if(a[j] == target) pos = j;
		}
		ll l = i/2 ,r = (i-1) - l;
		if(rev == 1) swap(l ,r);
		rev ^= 1;

		vector<ll> d;
		for(int j = 0 ;j < l ;j++) d.PB(1);
		if(pos - l > 0) d.PB(pos-l);
		if(n-r-pos > 0) d.PB(n-r-pos);
		for(int j = 0 ;j < r ;j++) d.PB(1);
		if(d.size() > 1) ans.PB(d);
		
		go(d);
	}
	if(n%2 == 0) ans.pop_back();
	cout << ans.size() <<"\n";
	for(auto & vi : ans){
	    cout << vi.size() <<" ";
	    for(ll &i : vi) cout << i <<" ";
	    cout << "\n";
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
