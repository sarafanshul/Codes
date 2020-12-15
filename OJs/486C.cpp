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
    ll n ,c;
    cin >> n >> c;
	string s ,s1="" ,s2="";
	cin >> s;
	if(c > n/2){ // always first half
	    reverse(ALL(s));
	    c = n-c+1;
	}
	// split the string (NOT NECCESSARY)
	for(int i = 0 ;i < n ;i++){
		if(i < (n+1)/2) s1+= s[i];
		else s2 += s[i];
	}
	reverse(ALL(s2));
	vector<ll> min_c((n+1)/2 ,0); // to store diff (does not need to be stored)
	for(int i = 0; i < (n)/2 ;i++){
	    min_c[i] = min({
	        max(0 ,('z' - s1[i]) + 1 + (s2[i] - 'a')),
	        max(0 ,(s1[i] - 'a') + 1 + ('z' - s2[i])),
	        abs(s1[i] - s2[i])
	    });
	}
	ll ans = 0;
// 	cout << s1+'\n'<<s2+'\n'<< min_c;
    ll mn_idx = -1 ,mx_idx = -1;
    for(int i = (n/2)-1 ; i>= 0 ;i--) if(min_c[i]){mx_idx = i ;break;}
    for(int i = 0 ;i < n/2 ; i++) if(min_c[i]){mn_idx = i;break;}
    for(int i = mn_idx ;i <= mx_idx ;i++){
        ans += min_c[i];
    }
    if(mn_idx == -1){cout << 0;return;}
    ans += mx_idx - mn_idx;
    // cout << ans<<"\n";
    ans += min(abs((mx_idx+1) - c) ,abs((mn_idx+1) - c));
    cout << ans ;
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
