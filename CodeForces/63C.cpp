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
	bool a[MAXN] = {0};
	ll n ,bi ,ci;
	cin >> n;
	for(ll i = 0 ;i < 10000 ;i++) a[i] = 1;
	
	auto gen = [](string s ,string x){
		pair<ll ,ll> ret = MP(0 ,0);
		
		for(ll i = 0; i < 4 ;i++) ret.F += (s[i] == x[i]);
		set<char> s1 ,x1;
		for(ll i = 0 ;i < 4 ;i++) s1.insert(s[i]) ,x1.insert(x[i]);
		std::vector<char> s3;
		if(s1.size() != 4) return MP(-1LL ,-1LL);
        set_intersection(ALL(s1), ALL(x1) ,std::back_inserter(s3) );
        ret.S = (ll)s3.size() - ret.F;
		return ret;
	};

	auto compare = [&](string x ,ll b ,ll c){
	   // cout << MP(b ,c)<<endl;
		for(ll i = 0 ; i < 10000 ;i++){
		    string s = to_string(i);
            while(s.size() < 4)s="0"+s;
		    
		    if(!a[i]) continue;
			pair<ll ,ll> pi =  gen(s ,x);
			if(pi.F != b || pi.S != c)a[i] = 0;
		}
	};

	while(n--){
	    string ai;
		cin >> ai >> bi >> ci;
		compare(ai ,bi ,ci);
	}
	
	ll cnt = 0 ,ans = -1;
	for(ll i = 0 ;i < 10000 ;i++) cnt += a[i];

    // cout << MP(cnt , ans);
	if(cnt > 1) cout << "Need more data\n";
	else if(cnt == 0) cout << "Incorrect data\n";
	else {
	    for(ll i = 123 ;i < 10000 ;i++){
	        if(a[i]){
	            string s = to_string(i);
                while(s.size() < 4)s="0"+s;
                cout << s<<"\n";
                break;
	        }
	    }
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
