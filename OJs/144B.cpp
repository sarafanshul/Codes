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
#define double long double
#define MP make_pair
// #define int long long
// #define MAX LONG_LONG_MAX
// #define MIN LONG_LONG_MIN

using namespace std;

#ifdef CUST_DEBUG // </COMMENT> the {ostream operator} modification(for redifination conflicts) after endif
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.x<<','<<p.y<<'>';return s;}
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.F<<','<<p.S<<'>';return s;}
template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>
ostream& operator<<(ostream&s,const T&v){s<<'[';for(auto&x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}
void __prnt(){cerr<<endl;} template<class T, class...Ts>void __prnt(T&&a,Ts&&...etc){cerr<<a<<' ';__prnt(etc...);}
#define print(...) __prnt(__VA_ARGS__)
#else
#define print(...)
#endif
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p){return cout<<"("<<p.F<<", "<<p.S<<")";}
template<typename A> ostream& operator<<(ostream &cout,vector<A> const &v){cout<<"[";for(int i=0;i<v.size();i++){if(i)cout<<", ";cout<<v[i];}return cout<<"]";}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p){cin>>p.F;return cin>>p.S;}

const size_t MAXN = 1e5 +7;

template<typename T = long long>
inline bool isClose(T x1,T y1,T x2,T y2,T r){
	if((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) <= r * r) return 1;
	return 0;
}

void check(){
	ll xa ,xb ,ya ,yb ,xmin ,xmax ,ymin ,ymax;
	cin >> xa >> ya >> xb >> yb;
	if(xa < xb){xmin = xa; xmax = xb;} else{xmin = xb; xmax = xa;}
    if(ya < yb){ymin = ya; ymax = yb;} else{ymin = yb; ymax = ya;}

    set<pair<ll ,ll>> coldG;

    for(ll k = ymin; k <= ymax; k++){coldG.insert(MP(xmin,k));}
    for(ll k = ymin; k <= ymax; k++){coldG.insert(MP(xmax,k));}
    for(ll k = xmin; k <= xmax; k++){coldG.insert(MP(k,ymin));}
    for(ll k = xmin; k <= xmax; k++){coldG.insert(MP(k,ymax));}

    ll rads = 0 ,xt ,yt ,tr;
	cin >> rads;
	vector<pair<ll ,ll>> radiators(rads);
	vector<ll> radii(rads);

	for(int k = 0; k < rads ; k++){
		cin >> xt >> yt >> tr;
		radiators[k] = MP(xt ,yt);
		radii[k] = tr;
	}
	for(ll k = 0 ;k < rads ;k++){
		auto myIter = coldG.begin(); 
        while(myIter != coldG.end()){
            if(isClose(myIter->first, myIter->second,radiators[k].F,radiators[k].S,radii[k])){
            	coldG.erase(myIter); 
            	myIter = coldG.begin();
            } else{myIter++;}
        }
	}
	cout << coldG.size();
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
