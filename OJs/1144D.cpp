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


void check(){
	int n;
	cin >> n;
	
	vector<int> a(n), cnt(200 * 1000 + 1);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		++cnt[a[i]];
	}
	
	int val = max_element(cnt.begin(), cnt.end()) - cnt.begin();
	int pos = find(a.begin(), a.end(), val) - a.begin();
	
	cout << n - cnt[val] << '\n';
	int siz = 0;
	for (int i = pos - 1; i >= 0; --i) {
		cout << 1 + (a[i] > a[i + 1]) << " " << i + 1 << " " << i + 2 << " " << '\n';
		a[i] = a[i + 1];
		++siz;
	}
	for (int i = 0; i < n - 1; ++i) {
		if (a[i + 1] != val) {
			assert(a[i] == val);
			cout << 1 + (a[i + 1] > a[i]) << " " << i + 2 << " " << i + 1 << " " << '\n';
			a[i + 1] = a[i];
			++siz;
		}
	}
	
	assert(siz == n - cnt[val]);
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
