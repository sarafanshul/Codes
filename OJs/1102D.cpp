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

const long long MAXN = 3e5 +7;

void check(){
	ll n;
	cin >> n;
	char s[MAXN];
	cin >> s;
	ll a[10] = {0};

	for(ll i = 0 ; i < n ; i++){
		a[ s[i] - '0' ]++;
	}
	ll md = n/3;
	for(ll i = n-1 ; i >= 0 ; i--){
		if(s[i] == '0' && (a[1] < md || a[2] < md) && (a[0] > md) ){
			if(a[2] < md ){
				a[2]++ ,a[0]--;
				s[i] = '2';
			}else {
				a[1]++ ,a[0]--;
				s[i] = '1';
			}
		}else if (s[i] == '1' && a[1] > md){
			// only 2 will result lexi
			if(a[2] < md){
				a[2]++ , a[1]--;
				s[i] = '2';
			}
		}
	}
	for(ll i = 0 ; i < n ; i++){
		if(s[i] == '2' && (a[1] < md || a[0] < md) && (a[2] > md)){
			if(a[0] < md){
				a[0]++ ,a[2]--;
				s[i] = '0';
			}else {
				a[1]++ ,a[2]--;
				s[i] = '1';
			}
		}else if(s[i] == '1' && a[1] > md){
			if(a[0] < md){
				a[0]++ ,a[1]--;
				s[i] = '0';
			}
		}
	}
	cout << s <<'\n';
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	int t = 1;	
	// cin >> t;
	for(int i = 1 ; i <= t ;i++){ check(); }
	return 0;
}
