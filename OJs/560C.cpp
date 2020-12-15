// Extend the sides of the hexagon to form an equilateral triangle (try to see why it is an equilateral triangle). Then the area of this triangle is sqrt(3)/4 * a^2 where a = a1 + a2 + a3 is the length of the side of the big triangle. Notice that the area of the original hexagon equals to the Area of big triangle - Area of 3 triangles ==> the area = sqrt(3)/4 * a^2 - sqrt(3)/4 * a1^2 - sqrt(3)/4 * a3^2 - sqrt(3)/4 * a5^2. where a1, a3, and a5 are the sides of the 3 triangles we added to the hexagon to form the big triangle.

// Now to see how many triangles of side = 1 exists we divide the area of the hexagon by the area of an equilateral triangle of side length = 1 (which equals sqrt(3)/4) ==> the answer = a^2 - a1^2 - a3^2 - a5^2

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

const long long MAXN = 1e5 +7;

void check(){
	ll a1 ,a2 ,a3 ,a4 ,a5 ,a6;
	cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
	cout << (a1 + a2 + a3)*(a1 + a2 + a3) - (a1*a1 + a3*a3 + a5*a5);
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
