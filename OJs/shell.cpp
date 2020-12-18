/*
ID: dt200021
TASK: shell
LANG: C++                 
*/
#ifndef CUST_DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#endif
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define F first
#define S second
#define ll long long
#define double long double
#define MP make_pair

using namespace std;

#ifdef CUST_DEBUG
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.F<<','<<p.S<<'>';return s;}
template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>
ostream& operator<<(ostream&s,const T&v){s<<'[';for(auto&x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}
void __prnt(){cerr<<endl;} template<class T, class...Ts>void __prnt(T&&a,Ts&&...etc){cerr<<a<<' ';__prnt(etc...);}
#define print(...) __prnt(__VA_ARGS__)
#else
#define print(...)
#endif

const long long MAXN = 1e5 +7;

int32_t main(){
	#ifndef CUST_DEBUG
	ofstream cout ("shell.out");
    ifstream cin ("shell.in");
	#endif
	int t = 1;	
	// cin >> t;
	for(int ii = 1 ; ii <= t ;ii++){
		int n;
		cin >> n;
		vector<int> cur(4) , points(4 ,0);
		for(int i = 0 ; i <= 3 ; i++) 
			cur[i] = i;

		for(int i = 0 ; i < n ; i++){
			int a , b , g;
			cin >> a >> b >> g;
			swap(cur[b] , cur[a]);
			print(cur ,points);
			points[cur[g]]++;
		}
		int mx = 0;
		for(int i : points)
			mx = max(mx ,i);
		cout << mx <<'\n';
		print(n ,mx);
	}
	return 0;
}
