/*
ID: dt200021
TASK: mixmilk
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
	ofstream cout ("mixmilk.out");
    ifstream cin ("mixmilk.in");
	#endif
	int t = 1;	
	// cin >> t;
	for(int ii = 1 ; ii <= t ;ii++){
		vector<int> c(4) , m(4);
		for(int i = 0 ; i < 3 ; i++) 
			cin >> c[i] >> m[i]; 
		int x = 100 ,i = 0;
		while(x--){
			// (i)%3 -> (i + 1)%3
			int fr = i%3 , to = (i + 1)%3;
			int can = m[fr] , y = c[to] - m[to];
			if(can > y){
				m[fr] -= y;
				m[to] += y;
			}else{
				m[fr] = 0;
				m[to] += can;
			}
			print( fr ,to ,m );
			i++;
		}
		cout << m[0] <<'\n' << m[1] <<'\n' << m[2] <<'\n';
	}
	return 0;
}
