#pragma GCC optimize("Ofast")  
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
#define MP make_pair
// #define int long long
// #define MAX LONG_LONG_MAX
// #define MIN LONG_LONG_MIN

using namespace std;

#ifdef LOCAL // setting up print debugging (yes lol)
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.F<<','<<p.S<<'>';return s;}
template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>
ostream& operator<<(ostream&s,const T&v){s<<'[';for(auto&x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}
void __prnt(){cerr<<endl;} template<class T, class...Ts>void __prnt(T&&a,Ts&&...etc){cerr<<a<<' ';__prnt(etc...);}
#define print(...) __prnt(__VA_ARGS__)
#else
#define print(...)
#endif
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.F << ", " << p.S << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
	cin >> p.F;return cin >> p.S;
}

const size_t MAXN = 1e6 +7;

vector<string> out = {"Carrots" ,"kiwis" ,"grapes"};

void check(){
	ll n ,m ,k ,t ,v ,u;
	cin >> n >> m >> k >> t;
	vector<ll> a;
	a.reserve(MAXN);
	while(k--){
		cin >> v >> u;
		v--;
		a.PB(v*m + u);
	}
	sort(ALL(a));
	ll pos;
	while(t--){
		ll j = 0;k = 0;
		cin >> v >> u;
		v--;
		pos = v*m + u;
		for(ll e : a){
			if(e < pos) k++;
			else if(e == pos) j = 1;
			else break;
		}
		pos -= k;pos = pos % 3;
        if(j)cout << ("Waste\n");
        else if(pos == 1)cout << ("Carrots\n");
        else if(pos == 2)cout << ("Kiwis\n");
        else cout << ("Grapes\n");
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	// cin.exceptions(cin.Failbit);
	int t = 1;	
	// cin >> t;
	for(int i = 1 ; i <= t ;i++){
		// cout << "Case "<< i << ":\n";
		check();
	}
	return 0;
}
