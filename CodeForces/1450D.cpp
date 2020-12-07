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

ll n ;

#define int ll
const int MAXLOG = 25;


int table[MAXLOG][MAXN];
int logs[MAXN];

void computeLogs() {
  	for (int i = 2; i < MAXN; i++) { logs[i] = logs[i / 2] + 1; }
}

void buildSparseTable(vector<int> &a ) {
	int curLen;
  	for (int i = 0; i <= logs[n]; i++) {
		curLen = 1 << i;
		for (int j = 0; j + curLen <= n; j++) {
	  		if (curLen == 1) { table[i][j] = a[j]; } 
	  		else { table[i][j] = min(table[i - 1][j], table[i - 1][j + (curLen / 2)]); }
		}
  	}
}

int getMin(int l, int r) {
  	int p = logs[r - l + 1];
  	int pLen = 1 << p;
  	return min(table[p][l], table[p][r - pLen + 1]);
}


void check(){

	cin >> n;
	vector<bool> p1(n+1 ,0);
	vector<ll> a(n);
	for(ll i = 0 ; i < n ; i++ ){
		cin >> a[i];
		p1[ a[i] ] = 1;
	}

	buildSparseTable(a );

	vector<ll> ans(n+1 ,0);
	ans[1] = 1;
	for(ll i = 1 ; i <= n ; i++){
		ans[1] &= (p1[i] != 0);
	}
	// binary search for last True k;

	auto is_per = [ & ] (ll x) -> bool {
		vector<bool> per(n ,0);

		for(ll i = 0 ; i + x < n ; i++){
			ll mn = getMin(i ,i + x);
			per[mn] = 1;
		}
		bool ret = 1;
		for(ll i = 1 ; i + x <= n ; i++){
			ret &= per[i];
		}
		return ret ;
	};

	ll l = 1 , r = n , m , last = n + 1;

	while( l < r){
		m = (l + r) / 2;
		
		if(is_per( m )){
			r = m ; 
			last = m;
		}else {
			l = m + 1;
		}
	}

	for(ll i = last+1 ; i <= n ; i++){
		ans[i] = 1;
	}
	
	for(ll i = 1 ; i <= n ; i++){
		cout << ans[i] ;
	}
	cout << '\n';
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	int t = 1;	
	cin >> t;

	computeLogs();
	
	for(int i = 1 ; i <= t ;i++){ check(); }
	return 0;
}
