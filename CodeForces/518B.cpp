// #pragma GCC optimize("Ofast")  // remove in mingw32 bit ;
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
int aA[30], a[30], A[30], i, j, k, bB[30], b[30], B[30], y, n, m;
void check(){
	string s1, s2;
    cin >> s1;
    cin >> s2;
    int l;
    l = s1.length();
    for (i = 0; i < l; i++){
        if (s1[i] >= 'a' && s1[i] <= 'z') a[s1[i] - 'a' + 1]++, aA[s1[i] - 'a' + 1]++;
        if (s1[i] >= 'A' && s1[i] <= 'Z') A[s1[i] - 'A' + 1]++, aA[s1[i] - 'A' + 1]++;
    }
    l = s2.length();
    for (i = 0; i < l; i++){
        if (s2[i] >= 'a' && s2[i] <= 'z') b[s2[i] - 'a' + 1]++, bB[s2[i] - 'a' + 1]++;
        if (s2[i] >= 'A' && s2[i] <= 'Z') B[s2[i] - 'A' + 1]++, bB[s2[i] - 'A' + 1]++;
    }
    for (i = 1; i <= 26; i++){
        y += a[i] > b[i] ? b[i] : a[i];
        y += A[i] > B[i] ? B[i] : A[i];
        n += aA[i] > bB[i] ? bB[i] : aA[i];
    }
    m = n - y;
    cout << y << ' ' << m;
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
