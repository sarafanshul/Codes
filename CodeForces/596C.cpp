#ifndef CUST_DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#endif
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

const long long MAXN = 3e5 +7;

struct point{
	ll x ,y;
	bool operator < (const point& other) const{
		if(x == other.x) return y < other.y;
		return x < other.x;
	}
} a[MAXN];

vector<ll> coords[MAXN];
ll coords_mp[MAXN] = {0};

void check(){
	ll n ,x ,y;
	const ll ad = 1e5;

	cin >> n;
	
	for(ll i = 0 ; i < n ;i++){
		cin >> x >> y;
		y += ad;
		a[i].x = x ,a[i].y = y;
	}
	
	sort(a ,a+n);
	
	for(ll i = 0 ; i < n ;i++){
		ll wi = a[i].y - a[i].x;
		coords[wi].PB(i);
	}
	
	ll w;
	vector<point> ans(n+1);
	map<ll ,ll> mx_x;
	
	for(ll i = 0 ; i < n ;i++){
		cin >> w;
		w += ad;
		if(coords_mp[w] >= coords[w].size()){
			cout << "NO\n";
			return;
		}
		ans[i] = a[ coords[w][coords_mp[w]] ];

		if(mx_x.count(ans[i].y) && mx_x[ ans[i].y ] > ans[i].x){
			cout <<"NO\n";
			return;
		}

		mx_x[ans[i].y] = ans[i].x;
		coords_mp[w]++;
	}
	cout <<"YES\n";
	for(ll i = 0 ; i < n ;i++){
		cout << ans[i].x <<' ' <<ans[i].y - ad <<'\n';
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
