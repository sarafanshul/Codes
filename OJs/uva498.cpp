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

ll n ,c[MAXN];

int32_t main(){
	#ifndef CUST_DEBUG
	// ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	// cin.exceptions(cin.Failbit);
		
	auto solve = [&](ll x){
	    
	   // for(int i = 0; i < n ;i++)printf("(%I64d)" ,c[i]);
		ll res= 0 ,xx = 1;
		for(int i = n-1 ;i >= 0 ;i--){
			res += c[i]*xx;
			xx *= x;
		}
		printf("%I64d" ,res);
	};

	ll len ,k ,x;
	char s[MAXN];
	while(gets(s)){
		len = strlen(s) ,k = 0;
		n = 0;
		while(k < len){
			while(k < len && s[k] == ' ') k++;
			if(k < len){
				sscanf(s+k ,"%I64d" ,&c[n++]);
				while(k < len && s[k] != ' ') k++;

			}
		}
		gets(s);
		len = strlen(s) ,k = 0;
		bool space = 0;
		while(k < len){
			while(k < len && s[k] == ' ')k++;
			if(k < len){
				sscanf(s + k ,"%I64d" ,&x);
				if(space) printf(" "); 
				space = 1;
				solve(x);
				while(k < len && s[k] != ' ')k++;
			}
		}
		printf("\n");
	}

	return 0;
}
