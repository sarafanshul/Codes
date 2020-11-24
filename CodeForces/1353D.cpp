// #pragma GCC optimize("Ofast")  // remove in mingw32 bit ;
// #pragma GCC target("avx,avx2,fma") 
// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("unroll-loops")
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

const long long MAXN = 1e6 +7;

struct seg{
	ll l , r , ln , tm;
	// greater and insertion ordered top
	bool operator<(const seg& other)const{
		if((r-l) ==  (other.r-other.l))return l < other.l;
		return (r-l) > (other.r-other.l);
	}
};

ll get_l(ll l ,ll r){
	return (l + r)/2;
}

void check(){
	set<seg> st;
	ll n;
	cin >> n;
	ll a[MAXN];
	ll ti = 0;
	st.insert(seg{1 ,n ,get_l(1 ,n) ,ti++});

	ll idx = 1;
	while(!st.empty()){
		seg s = *st.begin();
		st.erase(st.begin());
		a[s.ln] = idx++;
		if(s.l < s.ln)
			st.insert(seg{s.l ,s.ln-1 ,get_l(s.l ,s.ln-1) ,ti++});
		if(s.ln < s.r)
			st.insert(seg{s.ln+1 ,s.r ,get_l(s.ln+1 ,s.r) ,ti++});
	}

	for(int i =1 ; i <= n ;i++){
		cout << a[i] <<" \n"[i == n];
	}
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	// cin.exceptions(cin.Failbit);
	int t = 1;	
	cin >> t;
	for(int i = 1 ; i <= t ;i++){
		// cout << "Case "<< i << ":\n";
		check();
	}
	return 0;
}
